#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
  DDRB = 0xFF;

  while(1)
  {
    PORTB ^= 0x20;
    _delay_ms(500);
  }
  return 0;
}
