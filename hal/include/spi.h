#ifndef SPI_H
#define SPI_H

#include "N76E003.h"
#include "SFR_Macro.h"

#define SPI_MODE0					clr_CPOL; clr_CPHA
#define SPI_MODE1					clr_CPOL; set_CPHA
#define SPI_MODE2					set_CPOL; clr_CPHA
#define SPI_MODE3					set_CPOL; set_CPHA

#define SPI_LSBFIRST			set_LSBFE
#define SPI_MSBFIRST			clr_LSBFE

#define SPI_DISABLE				clr_SPIEN
#define SPI_ENABLE				set_SPIEN

#define SPI_SET_DIVISOR		SPICLK_DIV16 // available divisors are /2, /4, /8 and /16; currently set to provide 250KHz clock with 4MHz

void spi_init(void);
unsigned char spi_transfer(unsigned char x);

#endif