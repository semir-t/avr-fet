#include <avr/io.h>        					
#define F_CPU 16000000L    											// Atmega is running @16MHz
#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include "delay.h"
#include "uart.h"


int cprintf(const char *fmt, ...);

int main(void)
{
	int k = 0; 
	
	initUART();		

	stdout = &uart_output;
	stdin  = &uart_input;

	
    cprintf("Test\r\n");
    cprintf("Print broja %d\r\n", 1234);
    cprintf("Print hex %x\r\n", 1234);
    cprintf("Print octal %x\r\n", 1234);
    cprintf("Print ptr %p\r\n", 1234);
    cprintf("Print stringa %s\r\n", "Test");
    cprintf("print char %c\r\n", 67);
}
