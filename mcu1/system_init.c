/*This implementation file holds the configuration and activation of all the ports used in the program
these are the ports for the door status, actuator and code send switch*/

#include "TM4C123GH6PM.h" //system header file that contains the initialization of all variables, ports and constants
#include "lock_system.h" //Personal header file that is specific to this project

/*This function is used to configure and activate all the ports and pis on the TM4C123 board
which will be used in the program apart from the UART*/

//GPIOB is for the DIP Switch defined as SWITCH
//GPIOD is for ACTUATOR Off-board LED defined as actuator
//GPIOF is for the door status as well as the send code switch defined as DOOR
void system_init(void)
{
	//we first start the PORTB, PORTD and PORTF hardware CLOCKS 
	SYSCTL->RCGCGPIO |= PORTBCLK | PORTFCLK | PORTDCLK;
	
	//SET GPIOB 0-7 pins as input by writing 0
	SWITCH->DIR |= 0x00; //0000 0000
	//enable all the pins for digital function
	SWITCH->DEN |= 0xFF; //1111 1111
	//enable PULL DOWN resistors for all the pins 0-7
	SWITCH->PDR |= 0xFF; //0000 0000
	
	//enable PD0 for output to serve as the ACTUATOR LED
	ACTUATOR->DIR |= 0x01; //0000 0001
	//enable PD0 for digital function
	ACTUATOR->DEN |= 0x01; //0000 0001
	
	//enable PF3,2,1 as output to serve as the DOOR status
	DOOR->DIR |= 0x0E; //0000 1110
	//enable digital function for PF3,2,1 as well as PF4 which will be used as the on-board code 
	//send switch
	DOOR->DEN |= 0x1E; //0001 1110
	//enable PF4 to be an output for the code send switch
	DOOR->DIR &= ~(0x0F); //~(0000 1111)
	//enable PULL UP resistor for the code send Switch PF4
	DOOR->PUR |= 0x10; //0001 0000
}

