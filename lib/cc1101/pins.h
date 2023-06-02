#ifndef PINS_H
#define PINS_H

#include 		"N76E003.h"

#define 		CC1101_CS_HIGH			CC1101_CS=1
#define 		CC1101_CS_LOW				CC1101_CS=0
#define			CC1101_CS						P12
#define			CC1101_CS_INIT			P12_PushPull_Mode; CC1101_CS_HIGH

#define			TI_CC_GDO0_PIN_HIGH	TI_CC_GDO0_PIN=1
#define			TI_CC_GDO0_PIN_LOW	TI_CC_GDO0_PIN=0
#define			TI_CC_GDO0_PIN			P13
#define			CC1101_GDO0_INIT		P13_Input_Mode

#endif