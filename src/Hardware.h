#pragma once

#include <iostream>
#include "ABE_ADCDACPi.h"
#include "pinOut.h"
#include <wiringPi.h>
#include <softPwm.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdexcept>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <chrono>
#include "LaserCol.h"

using namespace std;
using namespace ABElectronics_CPP_Libraries;

namespace Hardware
{
	void setup();
	void update();
	void close();

	void setLaserPos( int16_t x, int16_t y );
	void setLaserCol( uint8_t r, uint8_t g, uint8_t b );
	void setLaserCol( LaserCol col );

	void setLaserRed( uint8_t r );
	void setLaserGrn( uint8_t g );
	void setLaserBlu( uint8_t b );

	void setBlank( bool _state );

	extern ADCDACPi adcdac;
	
	extern uint8_t lastR;
	extern uint8_t lastG;
	extern uint8_t lastB;

	extern bool laserBlank;
	extern bool threadRunning;
	const int pointDelay = 1;
	const int laserCentreX = 0;
	const int laserCentreY = 0;

}
