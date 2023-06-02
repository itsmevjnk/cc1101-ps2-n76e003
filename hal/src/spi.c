#include "spi.h"

void spi_init(void) {
	P0M1 &= ~(SET_BIT0 | SET_BIT1); P0M2 &= ~(SET_BIT0 | SET_BIT1); // set P0.0 (MOSI) and P0.1 (MISO) to quasi mode, this is quicker than two separate macros
	P10_Quasi_Mode; // set P1.0 (SPCLK) to quasi mode
	
	/* free P1.5 (SS) for GPIO */
	set_DISMODF;
	clr_SSOE;
	
	set_MSTR; // set SPI to run in master mode
	SPI_SET_DIVISOR; // set divisor (defined in spi.h)
	
	set_SPIEN; // enable SPI (no interrupt)
}

unsigned char spi_transfer(unsigned char x) {
	SPDR = x;
	while(!(SPSR & SET_BIT7)); // wait for TX completion
	clr_SPIF; // clear TX complete flag
	return SPDR; // return response
}