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

const char message[] = "DEBUG";
uint16_t length = 5;
uint32_t clockFreq;
uint32_t delay_val = 20000000 / 10000;
/*
 * The system performs measurements every SLEEP_TIME (rtc.h) seconds and prints the measurement via UART - this is used to work with the external logging solution,
 * for the reasons stated by me during the technical meeting. Basically, anything with uart and an SD card will do just fine, or something on computer (terminal or something\
 * smarter, like datalogger). Also, during the sleep one can plug in the uart converter and send a byte - that would also result in tdr data being sent back.
 */
int main(int argc, char *argv[])
{
    init_system();
	for (int i = 0; i < 4; i++) {
		adi_gpio_SetHigh(ADI_GPIO_PORT0, ADI_GPIO_PIN_14);
		// Create 1s Delay
		delay_val = 20000000 / 10000;
		delay_val *= 100;
		while (--delay_val) {
		}
		adi_gpio_SetLow(ADI_GPIO_PORT0, ADI_GPIO_PIN_14);
		// Create 1s Delay
		delay_val = 20000000 / 10000;
		delay_val *= 100;
		while (--delay_val) {
		}
	}


    /*
	// Create 1ms Delay
	adi_pwr_GetClockFrequency(ADI_CLOCK_HCLK, &clockFreq);
	uint32_t delay_val = clockFreq / 15000;
	delay_val *= 1000;
	while (--delay_val) {
	}
    uart_init();
    */
    // DEBUG CODE

    while(1) {
    	// Toggle pin
    	adi_gpio_Toggle(ADI_GPIO_PORT0, ADI_GPIO_PIN_14);

    	// Send UART data
    	//uart_init();
    	//uart_write(message, length);
    	//uart_deinit();

    	// Create 1ms Delay
    	delay_val = 20000000 / 10000;
    	delay_val *= 1;
    	while(--delay_val) {}

    	iHibernateExitFlag = 0;
    	rtc_UpdateAlarm();
    	enter_hibernation();
    }


	/*
	 *
	struct tdr_data tdr_data[TDR_MEMORY_SIZE];
	uint16_t index = 0;
	uint16_t package_counter = 5;

	packageNumber = 0;

	while(1)
	{
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
 			xint_uart_disable();
			init_store();
			run_and_store_measurements(tdr_data, &index);
			uart_init();
		    uint32_t delay_val = 1600; // 20ms
		    while(--delay_val){};
			print_tdr_data_to_uart(tdr_data);
			uart_deinit();
			send_data_package(tdr_data, package_counter);
			packageNumber++;
			iHibernateExitFlag = 0;
			rtc_UpdateAlarm();
			xint_uart_enable();
			enter_hibernation();
		}
	}
	*/
	return 0;
}
