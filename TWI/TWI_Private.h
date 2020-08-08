/*
 * 	TWI_Private.h
 *
 *  Created on: Mar 12, 2020
 *  Author: Bebo
 *
 */

#ifndef TWI_TWI_PRIVATE_H_
#define TWI_TWI_PRIVATE_H_

/*****************************************************************************/


#define TWI_ISR			__vector_17

/* the interrupt function depend on vector sent to it go back to vector table   */
#define	ISR( vector )			void vector (void) __attribute__ ((signal,used, externally_visible)) ; \
								void vector (void)

/*****************************************************************************/



#endif /* TWI_TWI_PRIVATE_H_ */
