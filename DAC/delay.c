

#include "delay.h"


static __IO uint32_t DelayCounter;


void SysTick_Handler(void) {
   DelayCounter++;
}


void delay_init(void) {
   
   SysTick->LOAD = (uint32_t)(SystemCoreClock / (1000UL - 1UL));

  
   NVIC_SetPriority(SysTick_IRQn,(1 << __NVIC_PRIO_BITS) - 1);

  
   SysTick->VAL = 0UL;

   
   SysTick->CTRL = (SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk);
}


void delay_ms(uint32_t ms) {
  
   SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

  
   DelayCounter = 0;
   while (DelayCounter < ms);

  
   SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

