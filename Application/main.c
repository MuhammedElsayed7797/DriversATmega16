/*
 * main.c
 *
 *  Created on: Jun 1, 2020
 *      Author: Bebo
 */


#include "../EEPROM/Eep.h"
#include "../MCU/Mcu.h"
#include "../Dio/Dio.h"
#include "../Timer1/Timer1.h"
#include "../TWI/TWI.h"
#include "../EEPROM_24C512/EEPROM_24C512.h"


void ToggleLed (void) ;

int main (void)
{

	CS_OFF ;
	Timer1_Init();
	Timer1_Interrupt_CallBack ( Timer1_COMPARE_A_INTERRUPT, ToggleLed );
	Timer1_Start();
	while(1);
	return 0 ;
}

void ToggleLed (void)
{
	*PORTA_REG ^= 0xFF ;
	return ;
}
