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

using namespace std;
using namespace ABElectronics_CPP_Libraries;

namespace Hardware
{
	void setup();
	void update();
	void close();

	void setLaserPos( int16_t x, int16_t y );
	void setLaserCol( int16_t r, int16_t g, int16_t b );

	void setLaserRed( int16_t r );
	void setLaserGrn( int16_t g );
	void setLaserBlu( int16_t b );

	void setBlank( bool _state );

	extern ADCDACPi adcdac;
	
	extern int r;
	extern int g;
	extern int b;
	extern int savedR;
	extern int savedG;
	extern int savedB;
	extern int lastR;
	extern int lastG;
	extern int lastB;

	extern bool laserBlank;
	extern bool threadRunning;
	const int pointDelay = 1;
	const int laserCentreX = 0;
	const int laserCentreY = 0;

}
