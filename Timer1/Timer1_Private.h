/*
 * 	Timer0_Private.h
 *
 *  Created on: Apr 13, 2020
 *  Author: Bebo
 *
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_


/*****************************************************************************/


#define ICU1_ISR			__vector_5
#define CMPA1_ISR			__vector_6
#define CMPB1_ISR			__vector_7
#define OVF1_ISR			__vector_8


/* the interrupt function depend on vector sent to it go back to vector table   */
#define	ISR( vector )			void vector (void) __attribute__ ((signal,used, externally_visible)) ; \
								void vector (void)


/*****************************************************************************/




#endif /* TIMER0_PRIVATE_H_ */
