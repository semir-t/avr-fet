#ifndef __UART_H
#define __UART_H

void initUART(void);
//void putcharUART(char c);

void putcharUART(char c, FILE *stream);
char getcharUART(FILE *stream);

// next two lines are for the application of the printf and scanf functions
FILE uart_output = FDEV_SETUP_STREAM(putcharUART, NULL, _FDEV_SETUP_WRITE);
FILE uart_input = FDEV_SETUP_STREAM(NULL, getcharUART, _FDEV_SETUP_READ);

/** Redirecting STDIN and STDOUT to UART
FDEV_SETUP_STREAM macro can be used to setup a buffer which is valid for
stdio operations. Initialized buffer will be of type FILE. 
You can define separate buffers for input and output. Alternatively 
you can define only one buffer which works for both input and output. 
First and second parameters are names of the functions which will be 
called when data is either read from or written to the buffer. */

#endif
