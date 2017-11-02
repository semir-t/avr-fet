#include "adc.h"
#include <avr/io.h>

#define ADC_ENABLE ADCSRA |= _BV(ADEN)
#define ADC_DISABLE ADCSRA &= ~(_BV(ADEN))

void initADC0()
{
  ADMUX = _BV(REFS0); // enable ADC0 with AVcc reference voltage
  ADC_ENABLE; // enable ADC
  ADCSRA |= _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0); // set ADC sampling rate to 125 kHz 
  ADCSRA |= _BV(ADSC); // start conversion 
  loop_until_bit_is_set(ADCSRA,ADIF);
  ADC_DISABLE; //disable ADC
}

uint16_t readADC0()
{
  uint16_t value = 0;
  ADC_ENABLE;
  ADCSRA |= _BV(ADSC); // start conversion
  loop_until_bit_is_set(ADCSRA,ADIF);
  value = ADC;
  ADC_DISABLE;
  return value;
}
