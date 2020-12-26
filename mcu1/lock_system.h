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
#define PORTBCLK (1U<<1)
#define PORTDCLK (1U<<3)
#define PORTECLK (1U<<4)
#define PORTFCLK (1U<<5)
#define UART_7 (1U<<7)
#define DOOR GPIOF
#define ACTUATOR GPIOD
#define SWITCH GPIOB

//******************************************************************************************
//Definition of all the function prototypes for this program
//******************************************************************************************
void UART7_init(void);
void system_init(void);
void UART7Tx (char PBdata);
void delayMs (int n);
char UART7Rx (void);
void access_granted(void);
void access_denied(void);
void lock_initiate(void);

#endif /* __LOCK_SYSTEM_H__*/ //preprocessor directive for end of definition

