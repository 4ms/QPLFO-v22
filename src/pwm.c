#include "pwm.h"

void init_pwm(void)
{
	  TIM_TimeBaseInitTypeDef  tim;
	  TIM_OCInitTypeDef  tim_oc;

	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 , ENABLE);

	  tim.TIM_Prescaler = 0;
	  tim.TIM_CounterMode = TIM_CounterMode_Up;
	  tim.TIM_Period = 1024;
	  tim.TIM_ClockDivision = 0;
	  tim.TIM_RepetitionCounter = 0;

	  TIM_TimeBaseInit(TIM1, &tim);

	  tim_oc.TIM_OCMode = TIM_OCMode_PWM2; //Mode 2 means pin is low until OC value reached
	  tim_oc.TIM_OutputState = TIM_OutputState_Enable;
	  tim_oc.TIM_OutputNState = TIM_OutputNState_Enable;
	  tim_oc.TIM_OCPolarity = TIM_OCPolarity_Low;
	  tim_oc.TIM_OCNPolarity = TIM_OCNPolarity_High;
	  tim_oc.TIM_OCIdleState = TIM_OCIdleState_Set;
	  tim_oc.TIM_OCNIdleState = TIM_OCIdleState_Reset;

	  tim_oc.TIM_Pulse = 100;
	  TIM_OC1Init(TIM1, &tim_oc);

	  tim_oc.TIM_Pulse = 300;
	  TIM_OC2Init(TIM1, &tim_oc);

	  tim_oc.TIM_Pulse = 600;
	  TIM_OC3Init(TIM1, &tim_oc);

	  tim_oc.TIM_Pulse = 900;
	  TIM_OC4Init(TIM1, &tim_oc);

	  TIM_Cmd(TIM1, ENABLE);

	  TIM_CtrlPWMOutputs(TIM1, ENABLE);

}

void update_pwm(uint32_t pwmval, uint8_t channel)
{
	pwmval = pwmval >> 2; //12-bit to 10-bit
	if (channel==0)
		TIM_SetCompare1(TIM1, pwmval);

	else if (channel==1)
		TIM_SetCompare2(TIM1, pwmval);

	else if (channel==2)
		TIM_SetCompare3(TIM1, pwmval);

	else if (channel==3)
		TIM_SetCompare4(TIM1, pwmval);

}
