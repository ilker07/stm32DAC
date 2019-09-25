#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f10x.h"                  // Device header


// Function prototypes
void delay_init(void);
void delay_ms(uint32_t ms);
void delaysleep_ms(uint32_t ms);

#endif // __DELAY_H


