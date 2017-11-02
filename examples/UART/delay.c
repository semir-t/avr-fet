#include "delay.h"

void delay_ms(uint16_t ms)
{/// delay in ms (1,2^16) usint TIMER2;
 /// error 
	TCCR2A |= 0x02;							 					// configure timer 2 in CTC mode
	OCR2A = 0x40;														// set counter max value to 64 
	TCNT2 = 0x00;
	TCCR2B |= (1 << CS22)|(1 << CS21);	 								// set clock prescaler to 256 aka 
																		// clock rate is 256/16MHz = 16us
																		// and start the timer 2
	while(ms > 0)
	{															
		while((TIFR2 & (1 << OCF2A)) == 0x00);						    // timer 2, Output Compare A Match Flag
		TIFR2 |= (1 << OCF2A);
		//TCNT2 = 0x00;
		ms--;
	}
	
	TCCR2A = 0x00; 	 
	TCCR2B = 0x00;											 		    // stop the timer 2
}

void delay_us(uint16_t us)
{/// delay in us (1,2^16) using TIMER2;
 /// error 
	TCCR2A |= 0x02;									 					// configure timer 2 in CTC mode
	OCR2A = 0x10;														// set counter max value to 16
	TCNT2 = 0x00; 
	TCCR2B |= (1 << CS20);		     	 								// set clock prescaler to  aka 				 								// set clock prescaler to 1 aka 
																		// clock rate is 1/16MHz = 1/16us
																		// and start the timer 2	
	while(us > 0)
	{															
		while((TIFR2 & (1 << OCF2A)) == 0x00);						    // timer 2, Output Compare A Match Flag
		TIFR2 |= (1 << OCF2A);
		//TCNT2 = 0x00;
		us--;
	}
	TCCR2A = 0x00; 	
	TCCR2B = 0x00;									 		    // stop the timer 2
}
				
void initStopwatch(void)
{/// setup and start TIMER1 counter to measure elapsed time in us!
	TCCR1B = (1 << WGM12);							 					// configure timer 1 in CTC mode
	OCR1A = 0xFFFF;														// set counter max value to 65535 
	TCNT1 = 0x0000;
	TCCR1B |= (1 << CS12)|(1 << CS10);				 					// set clock prescaler to 1024 aka 64us
}

uint32_t stopStopwatch(void)
{/// stop TIMER1 and return elapsed time in us!
	// stopwatch works for time intervals lower than 1 s!!!!
	uint32_t r_val;
	
	TCCR1B = 0x00;											 		    // stop the timer 1
	r_val = TCNT1;
	TIFR1 |= (1 << OCF1A);												// clear the interrupt flag
	r_val = r_val << 6;
	return r_val;
}

void initLongStopwatch(void)
{
	delay_sec = 0;
	ASSR = 0x60;
	TCNT1 = 0x00;
	//cli();
	TCCR1B = (1 << WGM12); 												// configure timer 1 for CTC mode
	OCR1A  = 15625; 													// set CTC compare value to 16ms @ 16MHz
	TCCR1B = ((1 << CS12));									// set prescaler to 1024; 15625*1024/16000000 = 1s
	TCNT1 = 0x00;
	TIMSK1 = (1 << OCIE1A);     										// set interrupt on compare match
    //sei();								   								// enable interrupts		
}

uint8_t stopLongStopwatch(void)
{// return value in seconds
	TIMSK1 = ~(1 << OCIE1A); 											// clear the interrupt
	TCCR1B = 0x00;											 		    // stop the timer 1
	TIFR1 |= 0xFF;												// clear the interrupt flag
	return delay_sec;
}

ISR(TIMER1_COMPA_vect)
{
	delay_sec++;
	TIFR1 |= 0xFF;
}

uint8_t getLongDelay(void)
{
	return delay_sec;
}

