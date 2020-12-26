/*This implementation file holds all sub-routines that will be executed when a specific message is received from the UART
There are 3 sub-routines to be executed namely access granted, access denied and lock initiated*/


#include "TM4C123GH6PM.h" //system header file that contains the initialization of all variables, ports and constants
#include "lock_system.h" //Personal header file that is specific to this project


/* Here is the function for access granted. It turns off the actuator which is the off-board LED and turns ofn the 
green on-board LED meaning that the DOOR is currently unlocked*/
void access_granted(void)
{
	ACTUATOR->DATA = 0x00; // actuator is turned off ones access is granted
	delayMs(500); // delay for 500 millisecond
	DOOR->DATA = 0x08; //Green LED is turned on meaning that the door is unlocked
}

/*This is the function for a denied access. onboard red LED stays on while the off-board LED which represents the 
actuator is flashed 5 times to tell the user that the actuator is unresponsive because the code entered is wrong*/
void access_denied(void)
{
	//int i; //initialise i for the loop
	//for (i=0;i<5;i++) //for loop to count through 5 times
	//{
		DOOR->DATA = 0x02; //Red LED stays on meaning that the door status remains locked
		ACTUATOR->DATA ^= 0x01; //toggle the off-board LED meaning that the actuator rejects the code
	//}	
				
}

/*This function is to tell the user that the lock sequence has been initiated*/
void lock_initiate(void)
{
	//int i=0; //initialise the function for the loop
	//while (i<10) //loop through the function 10 times while toggling the actuator (offboard LED), and the offboard LED colour changes
	//{
		DOOR->DATA = 0x02 | 0x04; //turn on the red and blue LED at the same time for a different colour to show door is about to be locked
		ACTUATOR->DATA ^= 0x01; // this toggles the actuator LED 
	//}
}
