#include "stm32f0xx_conf.h"



/* function definitions */
void TIM3_init();

void SysTick_Handler(void) {
  static uint16_t tick = 0;

  switch (tick++) {
  	case 100:
  		tick = 0;
  		//GPIOA->ODR ^= GPIO_Pin_5;
  		break;
  }
}

int main(void)
{

	RCC->AHBENR |= RCC_AHBENR_GPIOAEN; 	// enable the clock to GPIOC
						//(RM0091 lists this as IOPCEN, not GPIOCEN)

  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_Init(GPIOA,&GPIO_InitStructure);

	//GPIOA->MODER = (1 << 16);
  //GPIOA->BSRR = GPIO_Pin_5;
  //GPIO_SetBits(GPIOA,GPIO_Pin_5);
	SysTick_Config(SystemCoreClock/100);
  TIM3_init();
	while(1) {
  //GPIOA->ODR ^= GPIO_Pin_5;
  }

}

void TIM3_init() {
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

  TIM_TimeBaseInitTypeDef TIM_InitStructure;
  TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_InitStructure.TIM_Period = 1000;
  TIM_InitStructure.TIM_Prescaler = 1;
  TIM_TimeBaseInit(TIM3,&TIM_InitStructure);

  TIM_Cmd(TIM3,ENABLE);
  /* IRQ for TIM3 */
  NVIC_SetPriority(TIM3_IRQn,0);
  NVIC_EnableIRQ(TIM3_IRQn);
  TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
}


void TIM3_IRQHandler()
{
  //GPIOA->BSRR = GPIO_Pin_5;
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
        GPIOA->ODR ^= GPIO_Pin_5;
    }
}

