#ifndef __UART_H
#define __UART_H

#include <stdlib.h>
#include <stdio.h>

void initUART(void);
//void putcharUART(char c);

void putcharUART(char c);
char getcharUART();

// next two lines are for the application of the printf and scanf functions
extern FILE uart_output;
extern FILE uart_input;

/** Redirecting STDIN and STDOUT to UART
FDEV_SETUP_STREAM macro can be used to setup a buffer which is valid for
stdio operations. Initialized buffer will be of type FILE. 
You can define separate buffers for input and output. Alternatively 
you can define only one buffer which works for both input and output. 
First and second parameters are names of the functions which will be 
called when data is either read from or written to the buffer. */

#endif
