/*
 * ATmega16_Reg.h
 *
 *  Created on: Jun 1, 2020
 *      Author: Bebo
 */

#ifndef COMMON_ATMEGA16_REG_H_
#define COMMON_ATMEGA16_REG_H_

/***********************************************************************************/

/* EEPROM registers */

#define TWBR_REG		( ( volatile uint8 * ) 0x20 )
#define TWSR_REG		( ( volatile uint8 * ) 0x21 )
#define TWAR_REG		( ( volatile uint8 * ) 0x22 )
#define TWDR_REG		( ( volatile uint8 * ) 0x23 )
#define TWCR_REG		( ( volatile uint8 * ) 0x56 )


#define TWBR_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x20 )
#define TWSR_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x21 )
#define TWAR_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x22 )
#define TWDR_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x23 )
#define TWCR_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x56 )

/***********************************************************************************/

/* TWI registers */

#define EECR_REG		( ( volatile uint8 * ) 0x3C )
#define EEDR_REG		( ( volatile uint8 * ) 0x3D )
#define EEARL_REG		( ( volatile uint8 * ) 0x3E )
#define EEARH_REG		( ( volatile uint8 * ) 0x3F )
#define EEAR_REG		( ( volatile uint16 * ) 0x3E )


#define EECR_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x3C )
#define EEDR_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x3D )
#define EEARL_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x3E )
#define EEARH_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x3F )


/***********************************************************************************/

/* MCU registers */

#define WDTCR_REG		( ( volatile uint8 * ) 0x41 )
#define OSCCAL_REG		( ( volatile uint8 * ) 0x51 )	/* just when OCDEN fuse is unprogrammed */
#define MCUCSR_REG		( ( volatile uint8 * ) 0x54 )
#define MCUCR_REG		( ( volatile uint8 * ) 0x55 )
#define GIFR_REG		( ( volatile uint8 * ) 0x5A )
#define GICR_REG		( ( volatile uint8 * ) 0x5B )


#define WDTCR_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x41 )
#define OSCCAL_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x51 )	/* just when OCDEN fuse is unprogrammed */
#define MCUCSR_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x54 )
#define MCUCR_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x55 )
#define GICR_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x5B )


/***********************************************************************************/

/* DIO register */

#define PIND_REG		( ( volatile uint8 * ) 0x30 )
#define DDRD_REG		( ( volatile uint8 * ) 0x31 )
#define PORTD_REG		( ( volatile uint8 * ) 0x32 )


#define PINC_REG		( ( volatile uint8 * ) 0x33 )
#define DDRC_REG		( ( volatile uint8 * ) 0x34 )
#define PORTC_REG		( ( volatile uint8 * ) 0x35 )

#define PINC_REG_BIT		( ( volatile AVR_RegisterBits * ) 0x33 )
#define DDRC_REG_BIT		( ( volatile AVR_RegisterBits * ) 0x34 )
#define PORTC_REG_BIT		( ( volatile AVR_RegisterBits * ) 0x35 )


#define PINB_REG		( ( volatile uint8 * ) 0x36 )
#define DDRB_REG		( ( volatile uint8 * ) 0x37 )
#define PORTB_REG		( ( volatile uint8 * ) 0x38 )


#define PINA_REG		( ( volatile uint8 * ) 0x39 )
#define DDRA_REG		( ( volatile uint8 * ) 0x3A )
#define PORTA_REG		( ( volatile uint8 * ) 0x3B )

#define SFIOR_REG		( ( volatile uint8 * ) 0x50 )
#define SFIOR_REG_BIT	( ( volatile AVR_RegisterBits * ) 0x50 )


/***********************************************************************************/

/* Timer1 Registers */


#define TCCR1A_REG	*( ( volatile uint8 * ) 0x4F )
#define TCCR1B_REG	*( ( volatile uint8 * ) 0x4E )
#define TIMSK_REG	*( ( volatile uint8 * ) 0x59 )
#define TIFR_REG	*( ( volatile uint8 * ) 0x58 )

#define TCNT1_REG	*( ( volatile uint16 * ) 0x4C )
#define OCR1A_REG	*( ( volatile uint16 * ) 0x4A )
#define OCR1B_REG	*( ( volatile uint16 * ) 0x48 )
#define ICR1_REG	*( ( volatile uint16 * ) 0x46 )

/***********************************************************************************/


#endif /* COMMON_ATMEGA16_REG_H_ */
