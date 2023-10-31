/*
 * EXTI_Cfg.h
 *
 *  Created on: Apr 23, 2023
 *      Author: Khaled Waled
 */

#ifndef INC_EXTI_CFG_H_
#define INC_EXTI_CFG_H_
/*macros for prebuild*/
/****************************************************************/
/** !comment : Please Enter INT0_SENS_CONTROL					*/
/** 		   				SC_LOW_LEVEL						*/
/*					    	SC_LOGIC_CHANGE						*/
/*							SC_FALLING_EDGE						*/
/*				    		SC_RISING_EDGE 						*/
/****************************************************************/
#define INT0_SENS_CONTROL 		SC_LOGIC_CHANGE
/****************************************************************/
/** !comment : Please Enter INT1_SENS_CONTROL					*/
/** 		   				SC_LOW_LEVEL						*/
/*					    	SC_LOGIC_CHANGE						*/
/*							SC_FALLING_EDGE						*/
/*				    		SC_RISING_EDGE 						*/
/****************************************************************/
#define INT1_SENS_CONTROL 		SC_LOW_LEVEL
/****************************************************************/
/** !comment : Please Enter INT2_SENS_CONTROL					*/
/** 		   				SC_LOW_LEVEL						*/
/*					    	SC_LOGIC_CHANGE						*/
/*							SC_FALLING_EDGE						*/
/*				    		SC_RISING_EDGE 						*/
/****************************************************************/
#define INT2_SENS_CONTROL       SC_LOW_LEVEL


/******************************************************************************************************/


#endif /* INC_EXTI_CFG_H_ */
