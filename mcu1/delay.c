/*This implementation file is for the delay used in this program. Though we have only one delay function written in milliseconds
using the system clock for the calculation. A variable is also expected to be passed into the function which represents the
time in milliseconds*/

//Personal header file that is specific to this project
#include "lock_system.h"

//delay n millisecond using 16MHz clock
void delayMs(int n)
{
	int i, j; //initialise the variables for the loop
	for (i=0;i<n;i++)
			for(j=0;j<8300;j++) //loop lasts approximately 1ms
			{} //do nothing for as long as the loop lasts
}
