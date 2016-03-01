/*
 * dig_inouts.c
 */

#include "dig_inouts.h"

const uint32_t TAPBUT_pins[4]={TAPBUT1_pin, TAPBUT2_pin, TAPBUT3_pin, TAPBUT4_pin};
const uint32_t PING_pins[4]={PING1_pin, PING2_pin, PING3_pin, PING4_pin};
const uint32_t RESET123_pins[3]={RESET1_pin, RESET2_pin, RESET3_pin};

 void TAPLED_ON(uint8_t x)
 {
	 switch (x)
	 {
		 case 0:
			 TAPLED1_GPIO->BSRR = TAPLED1_pin;
			 break;
		 case 1:
			 TAPLED2_GPIO->BSRR = TAPLED2_pin;
			 break;
		 case 2:
			 TAPLED3_GPIO->BSRR = TAPLED3_pin;
			 break;
		 case 3:
			 TAPLED4_GPIO->BSRR = TAPLED4_pin;
			 break;
	 }
 }

 void TAPLED_OFF(uint8_t x)
 {
	 switch (x)
	 {
		 case 0:
			 TAPLED1_GPIO->BRR = TAPLED1_pin;
			 break;
		 case 1:
			 TAPLED2_GPIO->BRR = TAPLED2_pin;
			 break;
		 case 2:
			 TAPLED3_GPIO->BRR = TAPLED3_pin;
			 break;
		 case 3:
			 TAPLED4_GPIO->BRR = TAPLED4_pin;
			 break;
	 }
 }


 uint32_t TAPBUT(uint8_t x) {return(!(TAPBUT_GPIO->IDR & TAPBUT_pins[x]));}

 uint32_t PING(uint8_t x) {return((PING_GPIO->IDR & PING_pins[x]));}

 uint32_t RESETJACK(uint8_t x) {return((x==3) ? ((RESET4_GPIO->IDR & RESET4_pin)) : ((RESET123_GPIO->IDR & RESET123_pins[x])));}



void init_dig_inouts(void){
	GPIO_InitTypeDef gpio;
	GPIO_StructInit(&gpio);

	//Configure outputs
	gpio.GPIO_Mode = GPIO_Mode_OUT;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	gpio.GPIO_OType = GPIO_OType_PP;
	gpio.GPIO_PuPd = GPIO_PuPd_NOPULL;

	//TAPLEDs
	RCC_AHBPeriphClockCmd(TAPLED_RCC, ENABLE);

	gpio.GPIO_Pin = TAPLED1_pin;	GPIO_Init(TAPLED1_GPIO, &gpio);
	gpio.GPIO_Pin = TAPLED3_pin;	GPIO_Init(TAPLED3_GPIO, &gpio);
	gpio.GPIO_Pin = TAPLED4_pin;	GPIO_Init(TAPLED4_GPIO, &gpio);

#ifndef DEBUG_VERSION
	gpio.GPIO_Pin = TAPLED2_pin;	GPIO_Init(TAPLED2_GPIO, &gpio);
#else
	gpio.GPIO_Mode = GPIO_Mode_AF;
	gpio.GPIO_Pin = TAPLED2_pin;	GPIO_Init(TAPLED2_GPIO, &gpio);
	GPIO_PinAFConfig(TAPLED2_GPIO, GPIO_PinSource13, GPIO_AF_0);
#endif

	//LFO output pins
	gpio.GPIO_Mode = GPIO_Mode_AF;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	gpio.GPIO_OType = GPIO_OType_PP;
	gpio.GPIO_PuPd = GPIO_PuPd_UP;

	RCC_AHBPeriphClockCmd(LFOPWM_GPIO_RCC, ENABLE);
	gpio.GPIO_Pin = LFOPWM1_pin | LFOPWM2_pin | LFOPWM3_pin | LFOPWM4_pin;
	GPIO_Init(LFOPWM_GPIO, &gpio);

	GPIO_PinAFConfig(LFOPWM_GPIO, LFOPWM1_source, GPIO_AF_2);
	GPIO_PinAFConfig(LFOPWM_GPIO, LFOPWM2_source, GPIO_AF_2);
	GPIO_PinAFConfig(LFOPWM_GPIO, LFOPWM3_source, GPIO_AF_2);
	GPIO_PinAFConfig(LFOPWM_GPIO, LFOPWM4_source, GPIO_AF_2);

	//Configure inputs
	gpio.GPIO_Mode = GPIO_Mode_IN;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_PuPd = GPIO_PuPd_UP;

	//TAP Buttons
	RCC_AHBPeriphClockCmd(TAPBUT_RCC, ENABLE);
	gpio.GPIO_Pin = TAPBUT1_pin | TAPBUT2_pin | TAPBUT3_pin | TAPBUT4_pin;	GPIO_Init(TAPBUT_GPIO, &gpio);

	//Ping jacks
	RCC_AHBPeriphClockCmd(PING_RCC, ENABLE);
	gpio.GPIO_Pin = PING1_pin | PING2_pin | PING3_pin | PING4_pin;	GPIO_Init(PING_GPIO, &gpio);

	//Reset jacks
	RCC_AHBPeriphClockCmd(RESET_RCC, ENABLE);
	gpio.GPIO_Pin = RESET1_pin | RESET2_pin | RESET3_pin;	GPIO_Init(RESET123_GPIO, &gpio);
	gpio.GPIO_Pin = RESET4;	GPIO_Init(RESET4_GPIO, &gpio);

}

/**exti_ins.c**/

void init_EXTI_inputs(void)
{
/*
 	EXTI_InitTypeDef   EXTI_InitStructure;
	NVIC_InitTypeDef   NVIC_InitStructure;

	  //Set Priority Grouping mode to 2-bits for priority and 2-bits for sub-priority
	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	  SYSCFG_EXTILineConfig(EXTI_PINGJACK_GPIO, EXTI_PINGJACK_pin);
	  EXTI_InitStructure.EXTI_Line = EXTI_PINGJACK_line;
	  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	  EXTI_Init(&EXTI_InitStructure);

	  NVIC_InitStructure.NVIC_IRQChannel = EXTI_PINGJACK_IRQ;
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	  NVIC_Init(&NVIC_InitStructure);
*/

}

/*
void EXTI2_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_PINGJACK_line) != RESET)
  {
	  //This should be software de-bounced, we can't rely on the external clock having a perfectly sharp rising edge...
	  //Probably need to set the interrupt to record both edges, and ignore the up if a down happens shortly thereafter...?
	  //Or grab PEG's ping code, which grabs the ping_tmr in the interrupt uses that to flag the main loop to check again if the jack is still high
	  //..and if so, then it initiates the new timing information


	  ping_button_state = 0;

		if (ping_jack_state==1){ //second time we got a rising edge
			ping_jack_state = 0;

			//Log how much time has elapsed since last ping
			ping_time=ping_tmr;

			//Reset the timers
			ping_ledbut_tmr=0;
			clkout_trigger_tmr=0;

			//Flag to update the divmult parameters
			flag_ping_was_changed=1;
		} else {

			// This is the first rising edge, so start the ping timer
			ping_tmr = 0;
			ping_jack_state = 1;
		}

    EXTI_ClearITPendingBit(EXTI_PINGJACK_line);
  }

}
*/









/*

// This handy routine checks each button and digital input jack
// to see if it's been low for a certain number of cycles,
// and high for a certain number of cycles.
// We shift 0's and 1's down a 16-bit variable (State[]) to indicate high/low status.

void debounce_inputs(void)
{
	static uint16_t State[2] = {0,0,0,0,0,0,0,0,0,0}; // Current debounce status

	if (INF1BUT) t=0xe000; else t=0xe001;
	State[1]=(State[1]<<1) | t;
	if (State[1]==0xf000){
		//handle pin going high
	}
}

*/
