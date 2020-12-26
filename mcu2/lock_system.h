//*******************************************************************************************
//
// LOCK SYSTEM HEADER FILE FOR FUNCTION PROTOTYPING AND PORT DEFINITION
//
//*******************************************************************************************




#ifndef __LOCK_SYSTEM_H__ /* first preprocessor directives for defining the terms in the header file
//where they are not defined in the program as well as avoiding multiple defining of those functions, variables
and constants*/
#define __LOCK_SYSTEM_H__ /*second pre processor directive that defines the constants, function prototypes
as well as variables*/

//******************************************************************************************
// Definition of all the ports, variables and constants in the program
//******************************************************************************************

#define PORTFCLK (1U<<5)
#define PORTECLK (1U<<4) //0x10 or 0001 0000 defined as PORTECLK variable written to the register that starts PORT E clock
#define UART_7 (1U<<7) /*0x80 or 1000 0000 defined as UART_7 variable written to the UART clock register to start
/UART 7 clock*/

//******************************************************************************************
//Definition of all the function prototypes for this program
//******************************************************************************************
void UART7Tx (char UNLOCK_REQUEST); //prototype declaration for UART7 Transfer expecting to taking a character UNLOCK_REQUEST
void system_init(void); //prototype declaration for system initialisation. it does not expect an input and there is no output
void UART7_init(void); //prototype for UART7 initialisation. it does not expect an input and there is no output
void delayMs (int n); //prototype declaration for delay in millisecond. expects an input n which will be an integer
char UART7Rx (void); // prototype declaration for UART7 receive function. it does not expect an input but there is an output
//which will be a character
void checking_code(void);

#endif /* __LOCK_SYSTEM_H__*/ //preprocessor directive for end of definition

