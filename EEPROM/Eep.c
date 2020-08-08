/*
 * Eep.c
 *
 *  Created on: Jun 1, 2020
 *      Author: Bebo
 */

#include "../EEPROM/Eep.h"


/***********************************************************************************/


/* this function write Data represented Data by inside EEPROM
 * in address location represented by Address which must be less than 511
 *
 * for this function it will return E_NOT_OK if another write operation is in progress
 * user can use polling over return type of this function or use EEPROM interrupt
 * to initiate another write operation as soon as old one is complete
 *
 * don't use another method except this function to write on EEPROM to avoid corruption of data
 *
 * 	CPU will be halted for 2 clock cycles after write operation is initiated
 *
 * 	after write operation is initiated it will take around 8.5 ms to complete wirte operation
 *
 * if this function used inside boot loader make sure that's no flash write is performed while
 * initiating EEPROM write operation
 *
 * */
StatusType Eep_Write ( uint16 Address, uint8 Data )
{
	StatusType ReturnResult = E_OK ;

	/* check if there is running write operation  */
	if( EECR_REG_BIT->Bit_1)
	{
		ReturnResult = E_NOT_OK ;
	}
	else
	{
		/* critical section to prevent another operation from modifying address or data */
		CS_ON ;

		/* set the address and data to write */
		*EEAR_REG = Address ;
		*EEDR_REG = Data ;
		/* Write a logical one to the EEMWE bit while writing a zero to EEWE in EECR*/
		__asm( " SBI 0x1C, 2 " ) ;
		/* Within four clock cycles after setting EEMWE, write a logical one to EEWE
		 * so that using C for |= to set this bit will cause to time out so use assembly */

		__asm( " SBI 0x1C, 1 " ) ;
		CS_OFF ; /* stop critical section */

	}

	return ReturnResult ;
}

/***********************************************************************************/


/* this function read EEPROM location represented by Address and return data inside
 * this location into Data variable
 *
 * for this function it will return E_NOT_OK if write operation is in progress
 * user can use polling over return type of this function or use EEPROM interrupt
 * to initiate read operation as soon as old write operation  is complete
 *
 * don't use another method except this function to Read from EEPROM to avoid corruption of data
 *
 * 	CPU will be halted for 4 clock cycles after read operation is complete
 * 	data to be read immediately available after read operation is initiated
 *
 *
 * */
StatusType Eep_Read ( uint16 Address, uint8 * Data )
{
	StatusType ReturnResult = E_OK ;


	/* check if there is running write operation  */
	if( EECR_REG_BIT->Bit_1)
	{
		ReturnResult = E_NOT_OK ;
	}
	else
	{
		/* critical section to prevent another operation from modifying address or data */

		CS_ON ;

		/* set the address and data to write */
		*EEAR_REG = Address ;


		/* Write a logical one to the EERE bit to initiate Read operation */
		__asm( " SBI 0x1C, 0 " ) ;

		*Data = *EEDR_REG ;

		CS_OFF ; /* stop critical section */
	}

	return ReturnResult ;
}

/***********************************************************************************/




