//****************************************************************
//
//
//
//****************************************************************

//First include the systems header file that holds all definitions for this specific target device
#include "TM4C123GH6PM.h" 
/*Include the project header file that holds all the function prototypes and other definitions 
specific for this project*/
#include "lock_system.h"

/* this is the main implementation file for the whole project that holds the main function
of the program as the first source to other sub-implementation files*/
int main()
{
	system_init(); // this function holds the system configuration for this project. 
	//All ports needed are configured in this function
	
	
	UART7_init(); // this is the UART initialisation function that configures the port for the UART
	//and as such set the required registers with the appropriate values
	
	delayMs(1); //after the system and UART are all set and configured, we delay for 1 millisecond before 
	//executing the program
	
	volatile unsigned char PBdata = 0x00;/* Set a variable to hold the DIP switch data which is to be 
	sent to MCU 2 through the UART. This is set as volatile unsigned char to tell the compiler that the hex value
	is an unsigned character that will change within the course of the program execution*/
	
	volatile unsigned long REQUEST = 0x00;/* Set a variable to hold the data coming from the UART which is
	which is recieved from MCU 2. This is set as volatile unsigned char to tell the compiler that the hex value
	is an unsigned character that will change within the course of the program execution*/
	
	while(1) //loop forever
	{
		char SW1; //SW1 is a variable declared to store the current status of the send switch and the pull up resistor
		SW1 = DOOR->DATA & 0x10; // we are storing the current status of the send switch 
		DOOR->DATA = 0x02; //this is turning on the red LED at start of the program to repres3ent that the door is locked
		PBdata = SWITCH->DATA; //Here we assign the DIP switch data to the initially declared variable PBdata
		if (SW1==0x00) /* The logic for when the send switch is pressed.
		if the send switch is pressed, it initiates the UART amd sends the already stored value of the DIP switch 
		through the UART0*/
		{
			delayMs (500); //A delay is  written here for 500 milliseconds to represent switch debouncing 
			UART7Tx(PBdata);// the DIP Switch data is sent in form of the PBdata through the UART
		}
		REQUEST = UART7Rx();/*A message is recieved from the UART and stored in a variable declared as REQUEST*/
		if (REQUEST == 0x02)/*This is the logic for the message received from the UART. 0x02 represents that the
		code from the DIP switch is verified and is correct, hence access should be granted or a request to unlock the door*/
		{
			access_granted();// this is the function call to run when access is granted
		}
		else if (REQUEST == 0x01)/*This is a message received only when access is granted, it tells the MCU to prepare to lock 
			the door*/
		{
			lock_initiate();//this is the function call that signifies the door is about to be locked
		}
		else /*the code gets here is the code is checked and is incorrect hence sends any message apart from the two
			messages above*/
		{
			access_denied();//this is the function for incorrect DIP code input, hence access is denied
		}
	}
}
