#include "TM4C123GH6PM.h" //system header file that contains the initialization of all variables, ports and constants
#include "lock_system.h" //Personal header file that is specific to this project

//This function is written to initialise and configure the UART. The UART channel used is UART 7
//no value is expected to be passed in or returned from this function
void UART7_init(void)
{
	SYSCTL->RCGCUART |= UART_7; //write 1 to the corresponding block number 7 on the UART Clock register
	SYSCTL->RCGCGPIO |= PORTECLK; //start the port E clock which will be used for the UART
	UART7->CTL = 0x00; /*first the UART is disabled before it is configured
	the BAUD rate is set to 9600 using the formula in the top of this implementation file
	and also in the report of this assignment. the integer part 326 is written in the IBRD register*/
	UART7->IBRD = 326;
	/*the fraction part 34 is written into the FBRD register*/
	UART7->FBRD = 34;
	/*0 is written to the UART clock source register to set it to use the system clock*/
	UART7->CC = 0x00;
	/*1 is written into specific blocks of the LCRH Register
	to set the UART for 8-bit, no parity, 1-stop bit and no FIFO*/
	UART7->LCRH = 0x60; //00110 0000
	/*The UART is enabled BY writting 1 into the block transfer TXE, receive RXE and enable*/
	UART7->CTL = 0x301; //0011 0000 0001
	
	//enable the digital function for PE0 and PE1 used for the UART
	GPIOE->DEN |= 0x03; //0000 0011
	//Set direction for PE0 and PE1 for output
	GPIOE->DIR |= 0x03; //0000 0011
	//Set PE0 and PE1 for an alternate function
	GPIOE->AFSEL |= 0x03; //0000 0011
	//when the alternate function has been selected, set the pins PE0 and PE1
	//for UART
	GPIOE->PCTL |= 0x11; 
}
/*This is the UART7 transmit, this waits for the transmit buffer to be available then 
sends the bits to the buffer. REQUEST is initialised to pass value into this UART function*/
void UART7Tx(char REQUEST)
{
	//wait untill TX buffer is not full, i.e TXFF (bit 5) of the UARTFR register
	while((UART7->FR & 0x20) != 0)
	{}
	UART7->DR = REQUEST; //send REQUEST
}

/*The UART7 receive function.
This function waits until a character is recieved then returns it*/
char UART7Rx(void)
{
	char PBdata; //declare a variable to store the data received
	
	/*wait until RX buffer is not full by checking bit 4 of the UARTFR register*/
	while ((UART7->FR &0x10) != 0)
	{}
	//read the received data from the UART DR register into the declared char
	PBdata = UART7->DR;
	return PBdata; //return the data
}

