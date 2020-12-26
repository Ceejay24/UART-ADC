#include "TM4C123GH6PM.h"
#include "lock_system.h"

void checking_code(void)
{
	int i;
	while (i<5)
	{
		GPIOF->DATA = 0x08;
		delayMs(500);
		GPIOF->DATA = 0;
		delayMs(500);
	}
}

