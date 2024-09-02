/*
 * pin_configuration.h
 *
 *  Created on: 27. maj 2022
 *      Author: au703540
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <adi_gpio.h>

/**
 * Renamed macros for easier pin identification. In compliance with Pin Allocation excel available in TECH Pipesense Sharepoint.
 */
#define INTEGRATOR1_PORT       				ADI_GPIO_PORT2
#define INTEGRATOR1_PIN         			ADI_GPIO_PIN_4

#define INTEGRATOR12_PORT       			ADI_GPIO_PORT2
#define INTEGRATOR12_PIN        		 	ADI_GPIO_PIN_5

//#define MICRO_IMP_S2_PORT       		 	ADI_GPIO_PORT2
//#define MICRO_IMP_S2_PIN         			ADI_GPIO_PIN_8
//
//#define MICRO_IMP_S1_PORT        			ADI_GPIO_PORT2
//#define MICRO_IMP_S1_PIN       			  	ADI_GPIO_PIN_9
//
//#define MICRO_IMP_S0_PORT       		 	ADI_GPIO_PORT2
//#define MICRO_IMP_S0_PIN    		     	ADI_GPIO_PIN_10

#define MICRO_SENSOR_EN_PORT				ADI_GPIO_PORT1
#define MICRO_SENSOR_EN_PIN					ADI_GPIO_PIN_6

#define MICRO_TH_EN_PORT					ADI_GPIO_PORT1
#define MICRO_TH_EN_PIN						ADI_GPIO_PIN_9

#define MICRO_TH_S0_PORT					ADI_GPIO_PORT1
#define MICRO_TH_S0_PIN						ADI_GPIO_PIN_8

#define MICRO_TH_S1_PORT					ADI_GPIO_PORT1
#define MICRO_TH_S1_PIN						ADI_GPIO_PIN_7

#define MICRO_RST_INT_PORT					ADI_GPIO_PORT0
#define MICRO_RST_INT_PIN					ADI_GPIO_PIN_9

#define MICRO_APWR_EN_PORT					ADI_GPIO_PORT0
#define MICRO_APWR_EN_PIN					ADI_GPIO_PIN_8

#define MICRO_COMP_ON_PORT					ADI_GPIO_PORT1
#define MICRO_COMP_ON_PIN					ADI_GPIO_PIN_11

#define MICRO_STM_START_PORT				ADI_GPIO_PORT0
#define MICRO_STM_START_PIN					ADI_GPIO_PIN_12

#define MICRO_REF_S1_PORT					ADI_GPIO_PORT1
#define MICRO_REF_S1_PIN					ADI_GPIO_PIN_14

#define MICRO_REF_S0_PORT					ADI_GPIO_PORT2
#define MICRO_REF_S0_PIN					ADI_GPIO_PIN_2

#define MICRO_INTEGRATOR_TEST_PORT			ADI_GPIO_PORT0
#define MICRO_INTEGRATOR_TEST_PIN			ADI_GPIO_PIN_14

#define UART_WAKEUP_PORT					ADI_GPIO_PORT0
#define UART_WAKEUP_PIN						ADI_GPIO_PIN_13

#define LORA_RST_PORT						ADI_GPIO_PORT2
#define LORA_RST_PIN						ADI_GPIO_PIN_1

#define LORA_DIO0_PORT						ADI_GPIO_PORT1
#define LORA_DIO0_PIN						ADI_GPIO_PIN_5

void analog_pin_init();
void digital_pin_init();
void i2c_pin_init();

void gpio_init();

#endif /* GPIO_H_ */
