#include <avr/io.h>
#include <avr/delay.h>



int main(void)
{
  DDRD |= (1 << PD6);
  TCCR0A |= (1 << WGM01) | (1 << WGM00) | (1 << COM0A1);
  TCCR0B |= (1 << CS00);
  OCR0A = 0;
  OCR0B = 0;

  while(1)
  {
    int i = 0;
    for(i = 0; i < 255; i += 10)
    {
      OCR0A = i;  
      _delay_ms(100);
    }
    for(i = 255; i > 0; i - 10)
    {
      OCR0A = i;  
      _delay_ms(100);
    }

  }
  return 0;
}
