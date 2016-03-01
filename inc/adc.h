/*
 * adc.h - adc setup
 */

#ifndef __adc__
#define __adc__

#include <stm32f0xx.h>

#define MIN_ADC_CHANGE 20

void init_adc(uint16_t *ADC_Buffer);

#endif
