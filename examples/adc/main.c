#include <avr/io.h>

#define LED_ON PORTD |= _BV(PD6)
#define LED_OFF PORTD &= !(_BV(PD6))


int main(void)
{
  DDRD |= _BV(PD6);
  /* Initialize ADC */
  ADMUX |= _BV(REFS0); // enable ADC on pin PC0 with referent voltage set to AVCC (+5 (V))
  ADCSRA |= _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0); // enable ADC on PORTC & set ADC frequency to 125 (kHz)
  
  int inputValue = 0;
  while(1)
  {
    /* Start ADC conversion */
    ADCSRA |= _BV(ADSC);
    loop_until_bit_is_clear(ADCSRA,ADSC);
    inputValue = ADC;
    if(inputValue > 512)
    {
      LED_ON;
    }
    else
    {
      LED_OFF;
    }
  }
  return 0;
}
