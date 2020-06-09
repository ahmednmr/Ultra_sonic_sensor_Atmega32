/*
 * Ultra_sonic.c
 *
 *  Created on: Oct 25, 2019
 *      Author: Nmr
 */

#include "Ultra_sonic.h"



void init_Ultra_sonic(void)
{

	timer_init();
	DDRD |=(1<<PD3);            //make pd3 output as a trigger
	DDRD &=~(1<<PD2);           //make pd2 input as it will be ECHO

}


unsigned int Ultra_sonic_Get_Distance(void)
{

	unsigned int total_time_in_timer=0,No_of_counts_in_timer=0,Distance=0;

	PORTD |=(1<<PD3);         //sent pulse with width 2 ms
    _delay_ms(2);
   PORTD &=~(1<<PD3);


	while(!((PIND&(1<<PD2))>>PD2));      //wait until receive high from echo

	TCNT1=0;                            //clear the timer to start counts

	while(((PIND&(1<<PD2))>>PD2));      //wait until receive LOW from echo


    No_of_counts_in_timer=TCNT1;

    total_time_in_timer=No_of_counts_in_timer*32;         //convert the counts to time as sys tick is 32US

    Distance=total_time_in_timer / 58;                   //convert time to distance



return Distance;

}
