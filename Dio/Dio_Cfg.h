/*
 * Dio_Cfg.h
 *
 *  Created on: Jun 8, 2020
 *      Author: Bebo
 */

#ifndef DIO_DIO_CFG_H_
#define DIO_DIO_CFG_H_


/* except for function select section,
 * all other section configuration won't take effect except if Dio_Init function is used */

/*****************************************************************************/

/* determine which function is used inside this module if FALSE is selected then
 * function won't be burned to flash and won't be visible for the user
 * */

#define DIO_INIT_ON 				TRUE

#define DIO_WRITE_PIN_ON 			TRUE

#define DIO_READ_PIN_ON 			TRUE

#define DIO_FLIP_PIN_ON 			TRUE

#define DIO_WRITE_PORT_ON 			TRUE

#define DIO_READ_PORT_ON 			TRUE

#define DIO_FLIP_PORT_ON 			TRUE

#define DIO_WRITE_GROUP_ON 			TRUE

#define DIO_READ_GROUP_ON 			TRUE

#define DIO_FLIP_GROUP_ON 			TRUE

#define DIO_SET_PIN_DIRECTION_ON 	TRUE

#define DIO_SET_PORT_DIRECTION_ON 	TRUE

#define DIO_SET_GROUP_DIRECTION_ON 	TRUE

#define DIO_SET_INTERRUPT_MODE_ON 	TRUE


/*****************************************************************************/

/* determine direction of every pin from I/O pins just DIO_INPUT & DIO_OUTPUT is allowed to use */

#define DIO_PIN0_DIRECTION			DIO_INPUT
#define DIO_PIN1_DIRECTION			DIO_INPUT
#define DIO_PIN2_DIRECTION			DIO_INPUT
#define DIO_PIN3_DIRECTION			DIO_INPUT
#define DIO_PIN4_DIRECTION			DIO_INPUT
#define DIO_PIN5_DIRECTION			DIO_INPUT
#define DIO_PIN6_DIRECTION			DIO_INPUT
#define DIO_PIN7_DIRECTION			DIO_INPUT
#define DIO_PIN8_DIRECTION			DIO_INPUT
#define DIO_PIN9_DIRECTION			DIO_INPUT
#define DIO_PIN10_DIRECTION			DIO_INPUT
#define DIO_PIN11_DIRECTION			DIO_INPUT
#define DIO_PIN12_DIRECTION			DIO_INPUT
#define DIO_PIN13_DIRECTION			DIO_INPUT
#define DIO_PIN14_DIRECTION			DIO_INPUT
#define DIO_PIN15_DIRECTION			DIO_INPUT
#define DIO_PIN16_DIRECTION			DIO_INPUT
#define DIO_PIN17_DIRECTION			DIO_INPUT
#define DIO_PIN18_DIRECTION			DIO_INPUT
#define DIO_PIN19_DIRECTION			DIO_INPUT
#define DIO_PIN20_DIRECTION			DIO_INPUT
#define DIO_PIN21_DIRECTION			DIO_INPUT
#define DIO_PIN22_DIRECTION			DIO_INPUT
#define DIO_PIN23_DIRECTION			DIO_INPUT
#define DIO_PIN24_DIRECTION			DIO_INPUT
#define DIO_PIN25_DIRECTION			DIO_INPUT
#define DIO_PIN26_DIRECTION			DIO_INPUT
#define DIO_PIN27_DIRECTION			DIO_INPUT
#define DIO_PIN28_DIRECTION			DIO_INPUT
#define DIO_PIN29_DIRECTION			DIO_INPUT
#define DIO_PIN30_DIRECTION			DIO_INPUT
#define DIO_PIN31_DIRECTION			DIO_INPUT
#define DIO_PIN32_DIRECTION			DIO_INPUT



/*****************************************************************************/

/* determine state of every pin from I/O pins just DIO_LOW & DIO_HIGH is allowed to use
 * if pin is input DIO_LOW will configure input as tri stated input
 * and DIO_HIGH will configure input as pulled up input
 * */


#define DIO_PIN0_STATE			DIO_LOW
#define DIO_PIN1_STATE			DIO_LOW
#define DIO_PIN2_STATE			DIO_LOW
#define DIO_PIN3_STATE			DIO_LOW
#define DIO_PIN4_STATE			DIO_LOW
#define DIO_PIN5_STATE			DIO_LOW
#define DIO_PIN6_STATE			DIO_LOW
#define DIO_PIN7_STATE			DIO_LOW
#define DIO_PIN8_STATE			DIO_LOW
#define DIO_PIN9_STATE			DIO_LOW
#define DIO_PIN10_STATE			DIO_LOW
#define DIO_PIN11_STATE			DIO_LOW
#define DIO_PIN12_STATE			DIO_LOW
#define DIO_PIN13_STATE			DIO_LOW
#define DIO_PIN14_STATE			DIO_LOW
#define DIO_PIN15_STATE			DIO_LOW
#define DIO_PIN16_STATE			DIO_LOW
#define DIO_PIN17_STATE			DIO_LOW
#define DIO_PIN18_STATE			DIO_LOW
#define DIO_PIN19_STATE			DIO_LOW
#define DIO_PIN20_STATE			DIO_LOW
#define DIO_PIN21_STATE			DIO_LOW
#define DIO_PIN22_STATE			DIO_LOW
#define DIO_PIN23_STATE			DIO_LOW
#define DIO_PIN24_STATE			DIO_LOW
#define DIO_PIN25_STATE			DIO_LOW
#define DIO_PIN26_STATE			DIO_LOW
#define DIO_PIN27_STATE			DIO_LOW
#define DIO_PIN28_STATE			DIO_LOW
#define DIO_PIN29_STATE			DIO_LOW
#define DIO_PIN30_STATE			DIO_LOW
#define DIO_PIN31_STATE			DIO_LOW
#define DIO_PIN32_STATE			DIO_LOW



/*****************************************************************************/

/* determine if external interrupts pin is enabled or not FALSE to disable interrupt */

#define DIO_INT0_ENABLE		FALSE
#define DIO_INT1_ENABLE		FALSE
#define DIO_INT2_ENABLE		FALSE



/*****************************************************************************/

/* determine mode of trigger for every interrupt choose value from Dio_InterruptMode values
 * just DIO_RISING_EDGE, DIO_FALLING_EDGE is allowed to use for interrupt 2 */

#define DIO_INT0_MODE		DIO_RISING_EDGE
#define DIO_INT1_MODE		DIO_RISING_EDGE
#define DIO_INT2_MODE		DIO_RISING_EDGE



/*****************************************************************************/

/* used to select whether pull up resistor is globally disable or not
 * if disabled then all input will be tri-stated independent of local pull up enable setting
 *
 * if FALSE then pull up resistor is golbally disabled
 *
 */

#define DIO_PULL_UP_GLOBAL_DISABLE 	FALSE


/*****************************************************************************/



#endif /* DIO_DIO_CFG_H_ */




