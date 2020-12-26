#include "TM4C123GH6PM.h"
#include "lock_system.h"

int main()
{
	system_init();
	UART7_init();
	delayMs(1);
	
	volatile unsigned char PBdata;
	volatile unsigned int PASSCODE = 0x01;
	volatile unsigned int UNLOCK = 0x02;
	//volatile unsigned int LOCK = 0x01;
	while (1)
	{
		GPIOF->DATA = 0x02;
		PBdata = UART7Rx();
		//checking_code();
		if (PASSCODE == PBdata)
		{
			UART7Tx(UNLOCK);
			delayMs(1);
		}
		else
		{
			int i;
			for (i=0;i<1;i++)
			{
				UART7Tx(0x00);
				delayMs(2000);
			}
		}
	}	
}

