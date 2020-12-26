#include "TM4C123GH6PM.h"
#include "lock_system.h"

void system_init(void)
{
	SYSCTL->RCGCGPIO |= PORTFCLK;
	GPIOF->DIR |= 0x0E;
	GPIOF->DEN |= 0x0E;
}

