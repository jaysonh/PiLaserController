#pragma once

#include <wiringPi.h>
#include <iostream>
#include <time.h>
#include <cmath>
#include "JayUtils.h"

namespace PWMGenerator
{
	void sineWave( float _period, 
		       float _amplitude, 
		       uint8_t _min, 
		       uint8_t _max, 
		       uint8_t _pin         );
};
