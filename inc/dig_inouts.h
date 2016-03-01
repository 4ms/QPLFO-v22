/*
 * dig_inouts.h
 */

#ifndef INOUTS_H_
#define INOUTS_H_

#include <stm32f0xx.h>

//INPUTS
//ADC: GPIOA GPIO_Pin_0 GPIO_Pin_1 GPIO_Pin_2 GPIO_Pin_3

//DEBUG_VERSION will disable the Tap Button LED for channel 2 (it's used by the SWD connection)
//#define DEBUG_VERSION
#define RELEASE_VERSION

#define TAPBUT_RCC RCC_AHBPeriph_GPIOA

#define TAPBUT_GPIO GPIOA
#define TAPBUT1_pin GPIO_Pin_4
#define TAPBUT1 (!(TAPBUT_GPIO->IDR & TAPBUT1_pin))
#define TAPBUT2_pin GPIO_Pin_5
#define TAPBUT2 (!(TAPBUT_GPIO->IDR & TAPBUT2_pin))
#define TAPBUT3_pin GPIO_Pin_6
#define TAPBUT3 (!(TAPBUT_GPIO->IDR & TAPBUT3_pin))
#define TAPBUT4_pin GPIO_Pin_7
#define TAPBUT4 (!(TAPBUT_GPIO->IDR & TAPBUT4_pin))

#define PING_RCC RCC_AHBPeriph_GPIOB
#define PING_GPIO GPIOB
#define PING1_pin GPIO_Pin_0
#define PING1 ((PING_GPIO->IDR & PING1_pin))
#define PING2_pin GPIO_Pin_1
#define PING2 ((PING_GPIO->IDR & PING2_pin))
#define PING3_pin GPIO_Pin_3
#define PING3 ((PING_GPIO->IDR & PING3_pin))
#define PING4_pin GPIO_Pin_4
#define PING4 ((PING_GPIO->IDR & PING4_pin))


#define RESET_RCC (RCC_AHBPeriph_GPIOB | RCC_AHBPeriph_GPIOF)

#define RESET123_GPIO GPIOB
#define RESET1_pin GPIO_Pin_5
#define RESET1 ((RESET123_GPIO->IDR & RESET1_pin))
#define RESET2_pin GPIO_Pin_6
#define RESET2 ((RESET123_GPIO->IDR & RESET2_pin))
#define RESET3_pin GPIO_Pin_7
#define RESET3 ((RESET123_GPIO->IDR & RESET3_pin))

#define RESET4_GPIO GPIOF
#define RESET4_pin GPIO_Pin_1
#define RESET4 ((RESET4_GPIO->IDR & RESET4_pin))


/*
#define EXTI_CLOCK_GPIO EXTI_PortSourceGPIOB
#define EXTI_CLOCK_pin EXTI_PinSource12
#define EXTI_CLOCK_line EXTI_Line12
#define EXTI_CLOCK_IRQ EXTI15_10_IRQn
*/


//OUTPUTS

#define TAPLED_RCC (RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOF)
#define TAPLED1_GPIO GPIOA
#define TAPLED2_GPIO GPIOA
#define TAPLED3_GPIO GPIOF
#define TAPLED4_GPIO GPIOA

#define TAPLED1_pin GPIO_Pin_12
#define TAPLED2_pin GPIO_Pin_13
#define TAPLED3_pin GPIO_Pin_0
#define TAPLED4_pin GPIO_Pin_15

#define TAPLED1_ON TAPLED1_GPIO->BSRRL = TAPLED1_pin
#define TAPLED1_OFF TAPLED1_GPIO->BSRRH = TAPLED1_pin

#define TAPLED2_ON TAPLED2_GPIO->BSRRL = TAPLED2_pin
#define TAPLED2_OFF TAPLED2_GPIO->BSRRH = TAPLED2_pin

#define TAPLED3_ON TAPLED3_GPIO->BSRRL = TAPLED3_pin
#define TAPLED3_OFF TAPLED3_GPIO->BSRRH = TAPLED3_pin

#define TAPLED4_ON TAPLED4_GPIO->BSRRL = TAPLED4_pin
#define TAPLED4_OFF TAPLED4_GPIO->BSRRH = TAPLED4_pin


#define LFOPWM_GPIO_RCC RCC_AHBPeriph_GPIOA
#define LFOPWM_GPIO GPIOA
#define LFOPWM1_pin GPIO_Pin_8
#define LFOPWM2_pin GPIO_Pin_9
#define LFOPWM3_pin GPIO_Pin_10
#define LFOPWM4_pin GPIO_Pin_11

#define LFOPWM1_source GPIO_PinSource8
#define LFOPWM2_source GPIO_PinSource9
#define LFOPWM3_source GPIO_PinSource10
#define LFOPWM4_source GPIO_PinSource11

void init_dig_inouts(void);
void init_EXTI_inputs(void);
void init_inputread_timer(void);

void TAPLED_ON(uint8_t x);
void TAPLED_OFF(uint8_t x);
uint32_t TAPBUT(uint8_t x);
uint32_t PING(uint8_t x);
uint32_t RESETJACK(uint8_t x);

#endif /* INOUTS_H_ */
