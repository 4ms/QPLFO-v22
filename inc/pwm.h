/*
 * pwm.h
 */

#ifndef PWM_H_
#define PWM_H_

#include <stm32f0xx.h>


void init_pwm(void);
void update_pwm(uint32_t pwmval, uint8_t channel);

#endif /* PWM_H_ */
