#include "spi.h"
#include "pins.h"
#include "TI_CC_CC1100-CC2500.h"
#include "N76E003.h"
#include "delay.h"

void TI_CC_SPISetup(void) 
{
	// set up HW pins
	CC1101_CS_INIT;
	CC1101_GDO0_INIT;
}

#define CC1101_SPI_SETUP				SPI_DISABLE; SPI_MODE0; SPI_MSBFIRST; SPI_ENABLE

void TI_CC_SPIWriteReg(char addr, char value)
{
	CC1101_SPI_SETUP;
  CC1101_CS_LOW;                        // /CS enable
	spi_transfer(addr);										// Send address
  spi_transfer(value);									// Send value
	CC1101_CS_HIGH;                       // /CS disable
}

void TI_CC_SPIWriteBurstReg(char addr, char *buffer, char count)
{
  char i;
	
	CC1101_SPI_SETUP;
  CC1101_CS_LOW;																// /CS enable
	spi_transfer(addr | TI_CCxxx0_WRITE_BURST);		// Send address
	for (i = 0; i < count; i++)
  {
		spi_transfer(buffer[i]);										// Send data
  }
  CC1101_CS_HIGH;																// /CS disable
}

char TI_CC_SPIReadReg(char addr)
{
  char x;

  CC1101_CS_LOW;						// /CS enable
	spi_transfer(addr);				// Send address
  x = spi_transfer(0);    	// Send dummy byte, get not-so-dummy byte
  CC1101_CS_HIGH;						// /CS disable

  return x;
}

void TI_CC_SPIReadBurstReg(char addr, char *buffer, char count)
{
  unsigned int i;

	CC1101_SPI_SETUP;
  CC1101_CS_LOW;
  spi_transfer(addr | TI_CCxxx0_READ_BURST);
  for (i = 0; i < count; i++) buffer[i] = spi_transfer(0); // Send dummy byte and store received byte in buffer
  CC1101_CS_HIGH;
}

char TI_CC_SPIReadStatus(char addr)
{
  char status;

	CC1101_SPI_SETUP;
  CC1101_CS_LOW;        											// /CS enable
  status = spi_transfer(addr | TI_CCxxx0_READ_BURST);  // Send address
  CC1101_CS_HIGH;         										// /CS disable

  return status;
}

void TI_CC_SPIStrobe(char strobe)
{
	CC1101_SPI_SETUP;
  CC1101_CS_LOW;        											// /CS enable
	spi_transfer(strobe);												// Send strobe
  CC1101_CS_HIGH;         										// /CS disable
}

void TI_CC_PowerupResetCCxxxx(void)
{
  CC1101_CS_HIGH;
  delay_us(30);
  CC1101_CS_LOW;
  delay_us(30);
  CC1101_CS_HIGH;
  delay_us(40);

	TI_CC_SPIStrobe(TI_CCxxx0_SRES);
}