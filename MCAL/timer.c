/*
 * timer.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Nmr
 */

#include "timer.h"



void timer_init(void)
{

	TCCR1A=0x00;
	TCCR1B=0b00000100;
	TCNT1=0;


}
