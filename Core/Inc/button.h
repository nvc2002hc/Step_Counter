/*
 * button.h
 *
 *  Created on: Jun 7, 2023
 *      Author: luong
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define PIN_RESET ((uint16_t)0x2000)
#define PIN_PAUSE ((uint16_t)0x1000)

void init_button(void);
uint16_t check(uint16_t GPIO_Pin);
#endif /* INC_BUTTON_H_ */
