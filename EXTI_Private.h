/*
` * EXTI_Private.h
 *
 *  Created on: Apr 23, 2023
 *      Author: Khaled Waled
 */

#ifndef INC_EXTI_PRIVATE_H_
#define INC_EXTI_PRIVATE_H_


/*chanels*/
#define  EXTI_INT0				1
#define  EXTI_INT1				2
#define  EXTI_INT2				3


/*sense control*/

#define SC_LOW_LEVEL			1
#define SC_LOGIC_CHANGE			2
#define SC_FALLING_EDGE			3
#define SC_RISING_EDGE          4

#define EXTI_GICR	    		(*(volatile u8*)(0x5B))


#define EXTI_GICR_INT1			7
#define EXTI_GICR_INT0			6
#define EXTI_GICR_INT2			5

#define EXTI_GIFR				(*(volatile u8*)(0x5A))


#define EXTI_GICR_INT1			7
#define EXTI_GICR_INT0			6
#define EXTI_GICR_INT2			5


#define EXTI_MCUCR				(*(volatile u8*)(0x5A))

#define EXTI_MCUCR_ISC00_PIN     0
#define EXTI_MCUCR_ISC01_PIN     1
#define EXTI_MCUCR_ISC10_PIN     2
#define EXTI_MCUCR_ISC11_PIN     3

#define EXTI_MCUCSR				(*(volatile u8*)(0x54))

#define EXTI_MCUCSR_ISC2_PIN     6

#endif /* INC_EXTI_PRIVATE_H_ */
