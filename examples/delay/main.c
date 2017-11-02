#include <avr/io.h>
#include <delay.h>


int main(void)
{
  DDRB = 0x20;
  while(1)
  {
    PORTB ^= _BV(PB5); // toggle led
    delay_us(20000);
  }
  return 0;
}
