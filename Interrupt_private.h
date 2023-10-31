/*
 * Interrupt_private.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Magico
 */

#ifndef INTERRUPT_PRIVATE_H_
#define INTERRUPT_PRIVATE_H_

#define GLOBAL_INTERRUPT         0X07     //number of global interrupt pin in statues register
#define SREG     *((volatile u8 *)0X5F)   //casting of adresses of statues register to can write in it

#endif /* INTERRUPT_PRIVATE_H_ */
