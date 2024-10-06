/*****************************************************************************
 * tdr-board-v4.c
 *****************************************************************************/

#include "tdr-board-v4_config.h"

#include "general_functions.h"
#include "rtc.h"
#include "structs.h"
#include "uart.h"
#include "shared.h"
#include "xint.h"
#include <adi_gpio.h> // DEBUG

// LED current = 0.1755mA + 0.3424mA = 0.5179mA
// BOARD sleep = 0.72mA


volatile uint32_t iHibernateExitFlag = 0;
volatile uint8_t print_flag = 0;

/*
 * The system performs measurements every SLEEP_TIME (rtc.h) seconds and prints the measurement via UART - this is used to work with the external logging solution,
 * for the reasons stated by me during the technical meeting. Basically, anything with uart and an SD card will do just fine, or something on computer (terminal or something\
 * smarter, like datalogger). Also, during the sleep one can plug in the uart converter and send a byte - that would also result in tdr data being sent back.
 */
int main(int argc, char *argv[])
{
    init_system();

	// DEBUG START
	volatile uint32_t *reg = (uint32_t *) 0x4004C040;
	uint32_t reg_value = *reg;

	if (reg_value & (1 << 29)) {
		adi_gpio_SetHigh(ADI_GPIO_PORT0, ADI_GPIO_PIN_14); // DEBUG blue
	} else {
		adi_gpio_SetLow(ADI_GPIO_PORT0, ADI_GPIO_PIN_14); // DEBUG blue
	}
	if (reg_value & (1 << 30)) {
		adi_gpio_SetHigh(ADI_GPIO_PORT2, ADI_GPIO_PIN_0); // DEBUG orange
	} else {
		adi_gpio_SetLow(ADI_GPIO_PORT2, ADI_GPIO_PIN_0); // DEBUG orange
	}
	// DEBUG END
	DelayMsMcu(5000);

	adi_gpio_OutputEnable(ADI_GPIO_PORT1, ADI_GPIO_PIN_0, true);
	adi_gpio_SetHigh(ADI_GPIO_PORT1, ADI_GPIO_PIN_0);


	struct tdr_data tdr_data[TDR_MEMORY_SIZE];
	uint16_t index = 0;
	uint16_t package_counter = 5;

	packageNumber = 0;

	while(1)
	{
		print_flag = 0; // DEBUG to never enter this if
 		if(print_flag)
		{
 			xint_uart_disable();
			rtc_enable(false);
			uart_init();
		    uint32_t delay_val = 1600; // 20ms
		    while(--delay_val){};
			print_flag = 0;
			print_tdr_data_to_uart(tdr_data);
			uart_deinit();
			iHibernateExitFlag = 0;
			rtc_enable(true);
			xint_uart_enable();
			enter_hibernation();
		}
		else
		{
 			//xint_uart_disable();
			//init_store();
			//run_and_store_measurements(tdr_data, &index);
			//uart_init();
		    //uint32_t delay_val = 1600; // 20ms
		    //while(--delay_val){};
			//print_tdr_data_to_uart(tdr_data);
			//uart_deinit();
			send_data_package(tdr_data, package_counter);
			packageNumber++;
			iHibernateExitFlag = 0;
			rtc_UpdateAlarm();
			//xint_uart_enable();
			enter_hibernation();
		}
	}
	return 0;
}
