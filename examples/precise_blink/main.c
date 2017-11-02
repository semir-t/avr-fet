#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define FCPU 16000000
#define TOGGLE_LED (PORTB ^= (1 << PB4))

/* volatile unsigned char elapsedSeconds = 0; */

/* ISR(TIMER1_COMPA_vect) */ 
/* { */
/*   ++elapsedSeconds; */
/*   if(elapsedSeconds == 5) */
/*   { */
/*     TOGGLE_LED; */
/*     elapsedSeconds = 0; */
/*   } */
/* } */
/* void timer_freq(float freq) */
/* { */
/*   TCCR1B |= (1 << CS12) | (1 << WGM12); // set prescaler 256 & enable CTC mode */
/*   TIMSK1 |= (1 << OCIE1A); // enable timer interupt */
/*   OCR1A = FCPU / ( 2 * 256 * freq) - 1; */
/* } */

int main(void)
{
  DDRB |= (1 << PB1);
  TCCR1A |= (1 << COM1A0); //enable timer 1 compare output channel A in toggle mode
  TCCR1B |= (1 << CS12) | (1 << WGM12); // set prescaler 256 & enable CTC mode
  /* TIMSK1 |= (1 << OCIE1A); // enable Timer interupt on compare */
  OCR1A = 62499; // Set CTC compare valueto 1 Hz at 16MHz AVR clock with the prescaler 256
  /* sei(); //enable global interupt */

  while(1) //Endless loop 
  {

  }
  return 0;
}




