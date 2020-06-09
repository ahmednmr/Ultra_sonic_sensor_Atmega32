/*
 * main.c
 *
 *  Created on: 5 Oct 2015
 *      Author: EmbeddedFab
 */
#include <avr/io.h>
#include <util/delay.h>
#include "MCAL/UART.h"

#include "HAL/Ultra_sonic.h"

/*              connection
 *
   VCC = +5VDC
   Trig = PD3
   Echo = PD2
    GND = GND
 *
 *
 *
 */
int main()
{
	unsigned int Distance=0;


	init_UART();
	init_Ultra_sonic();

	 UART_SEND_string("Init Done \r\n");
    _delay_ms(1000);

	while(1)
	{


		Distance=Ultra_sonic_Get_Distance();
	  	UART_SEND_string("\r\n Distance =");
	    UART_SEND_number(Distance);
	    UART_SEND_string("cm \r\n");

        _delay_ms(2000);

	}
	return 0;
}


