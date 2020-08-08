

/*
 * Mcu.h
 *
 *  Created on: Jun 1, 2020
 *      Author: Bebo
 */

#ifndef MCU_MCU_H_
#define MCU_MCU_H_


#include "../Common/Utils.h"
#include "../MCU/Mcu_Cfg.h"



/***********************************************************************************/


/* for all modes this action will cause wake up if enabled
 * external reset
 *  Brown-out reset
 *  Watchdog reset
 *  External interrupt (level trigger)
 *  TWI address match
 *  */

/*****************************/

/* in this mode CPU stopped and rest of modules continue operating
 *
 * wake up done by any enabled interrupt from operating modules
 *
 * in this mode Analog Comparator should be disable ( if not needed ) to save power
 *
 * if ADC enabled then conversion will start automatically when entering this mode
 *
 * */
#define MCU_IDLE_SLEEP				0x40


/*****************************/

/* this mode used to enhance resolution of measured ADC sample
 *
 * in this mode just if enabled, ADC and async module continue to run
 * External interrupts(depend on level triggering)
 * TWI address watch
 * Timer2 if clocked Async
 *
 * in this mode Analog Comparator should be disable ( always ) to save power
 *
 * wake up done by
 * ADC interrupt, Timer2 interrupt (clock Async), EEPROM/SPM ready interrupt
 *
 * if ADC enabled then conversion will start automatically when entering this mode
 *
 * */
#define MCU_ADC_SLEEP				0x50

/*****************************/

/*
 * in this CPU and all modules are stopped except async operation
 * TWI address watch, external interrupt level trigger, watchdog
 *
 * this mode has a wake up time depend on clock source selected CKSEL, SUT fuses
 * refer to data sheet for more details on wake up time
 *
 * */
#define MCU_POWER_DOWN_SLEEP		0x60

/*****************************/

/*
 * this mode just like MCU_POWER_DOWN_SLEEP but with exception that
 * Timer 2 will continue to work if clocked with Async clock
 * if not it recommended to use MCU_POWER_DOWN_SLEEP cause in this case
 * if MCU_POWER_SAVE_SLEEP used then Timer2 register will be undefined after wake up
 * */
#define MCU_POWER_SAVE_SLEEP		0x70


/*****************************/

/* this mode just used case clock source is external crystal/resonator
 *
 * it just like MCU_POWER_DOWN_SLEEP with exception that oscillator keep running
 * so it just need 6 clock cycles to wake up */
#define MCU_STANDBY_SLEEP			0xE0

/*****************************/

/* this mode just used case clock source is external crystal/resonator
 *
 * it just like MCU_POWER_SAVE_SLEEP with exception that oscillator keep running
 * so it just need 6 clock cycles to wake up */
#define MCU_EXTENDED_STANDBY_SLEEP	0xF0

/* this data type used with function Mcu_Sleep and has a value of Macros above */
typedef uint8 Mcu_SleepMode ;


/***********************************************************************************/

/* no reset happen from last use of this function */
#define MCU_NO_RESET		0x00

/* reset caused because VCC is go less than 1.3~2.3 V*/
#define MCU_POWER_ON_RESET	0x01

/* reset happen due to low level on RESET pin for more than 1.5 us */
#define MCU_EXTERNAL_RESET	0x02u

/* reset happen because VCC is go less than 3.6~4.5V  and brown-out detector was enabled*/
#define MCU_BROWN_OUT_RESET	0x04u

/* reset happen because watchdog time out */
#define MCU_WATCHDOG_RESET	0x08u

/* reset happen due to JTAG reset */
#define MCU_JTAG_RESET		0x10u

/* used with function Mcu_ResetReason to hold reset reason */
typedef uint8 Mcu_ResetType ;

/***********************************************************************************/


/* used to calibrate internal oscillator clock frequency
 * as CalibrationValue increase frequency will increase
 * refer to page 30 of data sheet to get more details  */
#define Mcu_InternalOscillator_Calibration( CalibrationValue )		*OSCCAL_REG = CalibrationValue


/***********************************************************************************/

/* used to reset watchdog timeout and start counting timeout period from 0 */
#define Mcu_WatchdogReset()		__asm( " WDR " )

/***********************************************************************************/

/* used to enable watchdog, after calling this if no watchdog reset or
 * watchdog disable happen till watchdog timeout MCU reset will occure */
#define Mcu_EnableWatchdog()	WDTCR_REG_BIT->Bit_3 = TRUE ;


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
 * */
void Mcu_Sleep ( Mcu_SleepMode  Mode ) ;

/***********************************************************************************/


/* this function return the reason of last reset
 * make sure to use it after every reset to clear reset flags
 * or when it used it may return unresolved value caused by or operation to many reset reasons
 * */
Mcu_ResetType Mcu_ResetReason ( void ) ;


/***********************************************************************************/


/* used to disable watchdog operation
 * disabling watch dog will reset it too
 * */
void Mcu_DisableWatchdog (void) ;

/***********************************************************************************/


/* this function take a input a prescaler value 0~7
 * as Prescaler value increase the watchdog time out increse
 * watchdog time out calculated by equation
 * 2^(Prescaler+14) microsecond
 * */
void Mcu_WatchdogPrescaler ( uint8 Prescaler ) ;


/***********************************************************************************/

/* this function used to move vector table between boot section and application section
 * if I/P is true then vector is moved to Boot section */
void Mcu_MoveVector_ ( boolean Boot  ) ;


/***********************************************************************************/


#endif /* MCU_MCU_H_ */
