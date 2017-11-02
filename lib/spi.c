//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Library for controling SPI. 
//
//IMPORTANT: If SPI is master mode, then SS pin should 
//be defined as output. If there is need to define this
//pin as input then one should be aware that if this pin
//gets in low logical state then MSTR bit in SPCR is 
//cleared. This means that SPI is now in slave mode.
//So if there is need to work in master mode with 
//SS pin declared as input, then before sending data
//one should test MSTR bit value. More info can be
//found in MCU datasheet.
//
//NOTE: spi_tx_byte() and spi_rx_byte() could be merged
//in one function if there is need for less memory 
//consumption.
//
//Author: Semir Tursunovic
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include "spi.h"

void spi_master_init(uint8_t prescaler)/*{{{*/
{
  //Set CSK,SSN & MOSI as output, everthing else is input
  //Set PB4(MISO) input
  SPI_DDR |= _BV(SPI_MOSI) | _BV(SPI_SCK) | _BV(SPI_SSN);
  SPSR |= (prescaler >> 2) & 0x01; // set prescaler value
  SPCR |= (prescaler & 0x03); // set prescaler value
  
  // enable SPI in master mode, clock line is low in idle state
  // sampling on rasing edge
  SPCR |= _BV(MSTR) | _BV(SPE);
}/*}}}*/
void spi_slave_init(void)/*{{{*/
{
  //Set MISO output, everthing else as input
  SPI_DDR |= _BV(SPI_MISO);
   
  // enable SPI in slave mode, clock line is low in idle state
  // sampling on rasing edge
  SPCR |=  _BV(SPE);
}/*}}}*/
void spi_tx_byte(uint8_t data)/*{{{*/
{
  SPDR = data; // send data to SPI buffer
  while(!(SPSR & _BV(SPIF))); // wait while data is send
  data = SPDR; // clear SPIF0 bit;
  return;
}/*}}}*/
uint8_t spi_rx_byte(void)/*{{{*/
{
  uint8_t data = 0;
  SPDR = data; 
  while(!(SPSR & _BV(SPIF))); // wait while data is received 
  data = SPDR; // read SPI buffer & clear SPIF0 bit;
  return data;
}/*}}}*/

uint8_t spi_rxtx_byte(uint8_t data)/*{{{*/
{
  // Load data into the buffer
  SPDR = data;
  //Wait until transmission complete
  while(!(SPSR & (1<<SPIF) ));

  //Return received data
  return(SPDR);
 }/*}}}*/
void spi_tx(uint8_t * data, uint8_t n_value)/*{{{*/
{
  uint8_t k = 0;
  for(k = 0; k < n_value ; ++k)
  {
    spi_tx_byte(data[k]);
  }
}/*}}}*/
void spi_rx(uint8_t * data, uint8_t n_value)/*{{{*/
{
  uint8_t k = 0;
  for(k = 0; k < n_value ; ++k)
  {
    data[k] = spi_rx_byte();
  }
}/*}}}*/

