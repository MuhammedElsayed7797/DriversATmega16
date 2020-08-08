/*
 * Mcu.c
 *
 *  Created on: Jun 1, 2020
 *      Author: Bebo
 */

#include "../MCU/Mcu_Private.h"
#include "../MCU/Mcu.h"


/***********************************************************************************/



/*
 * this function used to make MCU enter sleep mode specified by Mode
 * this function won't return except after wake up
 * after wake up the CPU will halt for 4 clock cycles before execute any instruction
 * if mode has a wake up time then CPU will halt for Wake up time + 4 cycles
 *
 * check that no EEPROM write operation in progress before entering sleep mode or
 * EEPROM clock will keep running and consume power during sleep mode
 *
 * if ADC is enabled it will consume power during all sleep mode so if not needed disable it
 * when enabling it after being disabled first conversion will be extended ( need more time )
 *
 *
 * Brown-out detector will be enabled in all sleep modes if BODEN fuse is programmed
 * in deeper sleep contribute significantly to the total current consumption
 *
 * watchdog timer will be enabled in all sleep mode if it's not disabled before sleep mode
 * in deeper sleep contribute significantly to the total current consumption
 *
 * internal voltage reference is disabled when
 * ADC disabled
 * Brown-out detector disabled
 * Analog comparator don't use it as input
 * if Analog comparator use it as input it will be enabled even if Analog comparator is stopped during sleep mode
 * in deeper sleep contribute significantly to the total current consumption
 * when turned on after being off it will need 80us to start up don't use any module depend on during this period
 *
 * make sure enabled interrupt inputs pin is not floating or have level close to VCC/2 in sleep modes other than IDLE, ADC
 *
 * avoid calling this function inside ISR or device will never wake up except if nested interrupt is enabled and triggered
 * interrupt has priority bigger than interrupt this function called in
 *
 * for external interrupts pin configured as o/p and interrupt is locally disabled
 * for all interrupt mode setting except low level interrupt
 * if o/p level is one before enter sleep mode this will set the corresponding interrupt flag after wake up
 * so before enable interrupt make sure to clear its flag to avoid accidental interrupt
 *
 * */

void Mcu_Sleep ( Mcu_SleepMode  Mode )
{
	*MCUCR_REG &= SLEEP_MODE_SELECT_MASK ;

	/* set selected sleep mode and set sleep enable bit */
	*MCUCR_REG |= Mode ;

	/* enter sleep mode */
	__asm( " SLEEP " ) ;

	/* clear sleep mode select bits and sleep enable bit */
	*MCUCR_REG &= SLEEP_MODE_SELECT_MASK ;


	return ;
}



/***********************************************************************************/

/* this function return the reason of last reset
 * make sure to use it after every reset to clear reset flags
 * or when it used it may return unresolved value caused by or operation to many reset reasons
 * */
Mcu_ResetType Mcu_ResetReason ( void )
{
	Mcu_ResetType ReturnResult = MCU_NO_RESET ;

	ReturnResult = *MCUCSR_REG & RESET_REASON_MASK ;

	/* clear reset flags */
	*MCUCSR_REG |= 0 ;

	return ReturnResult ;
}


/***********************************************************************************/

/* used to disable watchdog operation
 * disabling watch dog will reset it too
 * */
void Mcu_DisableWatchdog (void)
{
	/* reset watchdog to avoid timeout during disable it */
	__asm( " WDR" ) ;

	/* In the same operation, write a logic one to WDTOE and WDE */
	*WDTCR_REG |= WATCHDOG_DISABLE_MASK ;

	/* Within the next four clock cycles, write a logic 0 to WDE */
	WDTCR_REG_BIT->Bit_3 =  FALSE ;

	return ;
}

/***********************************************************************************/

/* this function take a input a prescaler value 0~7
 * as Prescaler value increase the watchdog time out increse
 * watchdog time out calculated by equation
 * 2^(Prescaler+14) microsecond
 * */
void Mcu_WatchdogPrescaler ( uint8 Prescaler )
{
	/* clear watchdog prescaler bits */
	*WDTCR_REG &= WATCHDOG_PRESCALER_MASK ;

	/* set new prescaler */
	*WDTCR_REG |= Prescaler ;

	return ;
}


/***********************************************************************************/

/* this function used to move vector table between boot section and application section
 * if I/P is true then vector is moved to Boot section */
void Mcu_MoveVector_ ( boolean Boot  )
{
	/* to restore value of another bits */
	uint8 Temp = *GICR_REG  & 0xFC ;
	if( Boot )
	{
		/* set IVSEL bit */
		Temp |= 0x02 ;
		/* set IVCE bit */
		GICR_REG_BIT->Bit_0 = TRUE ;

		/* Within four cycles, write the desired value to IVSEL while writing a zero to IVCE */
		*GICR_REG = Temp ;
	}
	else
	{
		/* set IVCE bit */
		GICR_REG_BIT->Bit_0 = TRUE ;
		/* Within four cycles, write the desired value to IVSEL while writing a zero to IVCE */
		*GICR_REG = Temp ;

	}
	return ;
}



/***********************************************************************************/


