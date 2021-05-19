#pragma once

#include <iostream>
#include "ABE_ADCDACPi.h"
#include "pinOut.h"
#include <wiringPi.h>
#include <softPwm.h>

using namespace std;
using namespace ABElectronics_CPP_Libraries;

namespace Hardware
{
	void setup();
	void update();

	void setLaserPos( int16_t x, int16_t y );
	void setLaserCol( uint8_t r, uint8_t g, uint8_t b );

	void setLaserRed( uint8_t r );
	void setLaserGrn( uint8_t g );
	void setLaserBlu( uint8_t b );

	extern ADCDACPi adcdac;
	

}
