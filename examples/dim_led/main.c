#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/delay.h>
#include <stdio.h>
#include "adc.h"
#include "uart.h"

#define LED_ON PORTD |= _BV(PD7)
#define LED_OFF PORTD &= ~(_BV(PD7))

int main(void)
{
  int k = 0;
  initADC0();
  initUART();
  stdout = &uart_output;
  stdin  = &uart_input;
  
  TCCR0A |= _BV(WGM00) | _BV(WGM01) | _BV(COM0A1); // enable PWM mode, clear OC0A on compare (non-inverting mode)
  TCCR0B |= _BV(CS00); // no prescaling
    
  DDRD |= _BV(DD7) | _BV(DD6);
   
  int analogVoltage = 0;

  while(1)
  {
    analogVoltage = readADC0() >> 2;
    OCR0A = analogVoltage;
    printf("RUN [%d]\r\n",analogVoltage);
    _delay_ms(10);
    k++;
  }
  return 0;
}
