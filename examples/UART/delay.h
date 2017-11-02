#ifndef __DELAY_H
#define __DELAY_H
#include <avr/io.h>  
#include <avr/interrupt.h>

void 		delay_ms(uint16_t ms);
void 		delay_us(uint16_t us);

void 		initStopwatch(void);				// call this function to start time measurement
uint32_t	stopStopwatch(void);				// call this function to stop time measurement and to receive elapsed time


void 		initLongStopwatch(void);
uint8_t 	stopLongStopwatch(void);
uint8_t 	getLongDelay(void);
volatile uint8_t delay_sec;
#endif
