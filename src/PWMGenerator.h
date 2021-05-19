#pragma once

#include <wiringPi.h>
#include <iostream>
#include <time.h>
#include <cmath>
#include "JayUtils.h"

namespace PWMGenerator
{
	int sineWave( const float _period, 
    	              const float _amplitude, 
		      const uint16_t _min, 
		      const uint16_t _max
		       );
};
