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

#ifndef __SPI_H
#define __SPI_H 

#include <avr/io.h>
#include "usart.h"
#include "print.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Pin Configuration
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define SPI_SSN               PB2
#define SPI_MOSI              PB3
#define SPI_MISO              PB4
#define SPI_SCK               PB5
#define SPI_DDR           DDRB
#define SPI_PORT          PORTB
#define SPI_PIN           PINB

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//User defined macros
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define SSN_LOW           (SPI_PORT &= ~_BV(SPI_SSN))
#define SSN_HIGH          (SPI_PORT |= _BV(SPI_SSN))

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Data transfer speed
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define SPI_BAUDRATE_PRESCALER_2        0x04
#define SPI_BAUDRATE_PRESCALER_4        0x00
#define SPI_BAUDRATE_PRESCALER_8        0x05
#define SPI_BAUDRATE_PRESCALER_16       0x01
#define SPI_BAUDRATE_PRESCALER_32       0x06
#define SPI_BAUDRATE_PRESCALER_64       0x02
#define SPI_BAUDRATE_PRESCALER_64_2X    0x07
#define SPI_BAUDRATE_PRESCALER_128      0x3


void spi_master_init(uint8_t);
void spi_slave_init(void);
void spi_tx_byte(uint8_t);
uint8_t spi_rx_byte(void);
uint8_t spi_rxtx_byte(uint8_t);
void spi_tx(uint8_t *, uint8_t);
void spi_rx(uint8_t *, uint8_t);


#endif /* ifndef __SPI_H */
