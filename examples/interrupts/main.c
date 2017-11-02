#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
#define LED_ON (PORTB |= (1 << PORTB4))
#define LED_OFF (PORTB &= ~(1 << PORTB4))
#define READ_S1 (PINB & (1 << PINB0))

ISR(INT0_vect)
{
  _delay_ms(1000);
  PORTB |= (1 << PORTB3);
  _delay_ms(1000);
  PORTB |= !(1 << PORTB3);
  return;
}

int main(void)
{
  DDRB |= (1 << PORTB4) | (1 << PORTB3); 
  EIMSK = (1 << INT0);
  EICRA = (1 << ISC00) | (1 << ISC01);

  sei();
  while(1)
  {
    LED_ON;
    _delay_ms(500);
    LED_OFF;
    _delay_ms(500);
  }
  return 0;
}
