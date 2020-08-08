/*
 * Eep.h
 *
 *  Created on: Jun 1, 2020
 *      Author: Bebo
 */

#ifndef EEPROM_EEP_H_
#define EEPROM_EEP_H_

#include "../Common/Utils.h"
#include "../EEPROM/Eep_Cfg.h"



/***********************************************************************************/
/***********************************************************************************/


/* this function enable EEPROM interrupt
 * interrupt will fire as long as no write operation on EEPROM
 * so take care when enabling it to make a write operation inside ISR
 * or to disable interrupt inside ISR or interrupt will keep firing after return
 *
 * avoid enable nested interrupt inside EEPROM ISR to avoid memory crash
 *
 * */
#define Eep_EnableInterrupt() 	__asm( " SBI 0x1C, 3 " )


/***********************************************************************************/


/*
 * this function disable EEPROM interrupt
 * */
#define Eep_DisableInterrupt() 	__asm( " CBI 0x1C, 3 " )


/***********************************************************************************/


/* this function check if there currnetly running write operation if
 * return TRUE then there's write operation in progress
 *
 * */
#define Eep_CheckWrite()	EECR_REG_BIT->Bit_1




/***********************************************************************************/
/***********************************************************************************/
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
StatusType Eep_Write ( uint16 Address, uint8 Data ) ;


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
StatusType Eep_Read ( uint16 Address, uint8 * Data ) ;

/***********************************************************************************/

#endif /* EEPROM_EEP_H_ */
