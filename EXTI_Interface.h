/*
` * EXTI_Interface.h
 *
 *  Created on: Apr 23, 2023
 *      Author: Khaled Waled
 */

#ifndef INC_EXTI_INTERFACE_H_
#define INC_EXTI_INTERFACE_H_
#include "STD_TYPES.h"
/*Functions for Prebuild*/

void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);
void EXTI_voidInt0Disable(void);
void EXTI_voidInt1Disable(void);
void EXTI_voidInt2Disable(void);

/*Functions for runtime*/



void EXTI_voidIntInit(u8 copy_Int_chanel,u8 copy_Int_trig_type);
void EXTI_voidIntDisable(u8 copy_Int_chanel);

#endif /* INC_EXTI_INTERFACE_H_ */
