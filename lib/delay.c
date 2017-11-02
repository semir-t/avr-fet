#include "delay.h"

void delay_ms(uint16_t delay) // used TIMER2 (8 bit)
{
  TCCR2A |= _BV(WGM21); // enable CTC mode
  TCCR2B |= _BV(CS22); // set prescaler to 64
  OCR2A = 0xF9; // set Output compare register value to 249
  TCNT2 = 0x00; // set timer/counter value to 0
  while(delay > 0)
  {
    loop_until_bit_is_set(TIFR2,OCF2A);
    TIFR2 |= _BV(OCF2A); // reset flag
    --delay;
  }

  /* Reset timer settings */
  TCCR2A = 0x00; 
  TCCR2B = 0x00; 
}

void delay_us(uint16_t delay) // used TIMER2 (8 bit)
{
  TCCR2A |= _BV(WGM21); // enable CTC mode
  TCCR2B |= _BV(CS20); // no prescaling
  OCR2A = 0x10; // set Output compare registar value to 16
  TCNT2 = 0x0; // reset timer/counter 
  while(delay > 0)
  {
    loop_until_bit_is_set(TIFR2,OCF2A);
    TIFR2 |= _BV(OCF2A); // reset flag
    --delay;
  }
  /* Reset timer settings */
  TCCR2A = 0x00; 
  TCCR2B = 0x00; 
}
