#include "PWMGenerator.h"

namespace PWMGenerator
{
	void sineWave( float   _period, 
		       float   _amplitude, 
		       uint8_t _min, 
		       uint8_t _max,
		       uint8_t _pin         )
	{
		struct timespec now;
		clock_gettime( CLOCK_REALTIME, &now );
		const struct tm * tms = localtime( &now.tv_sec );
		int sec =  now.tv_sec % 100000;
		int ms  = (int)now.tv_nsec / 1000000;
		
		float timef = (float)sec + ( (float)ms / 1000.0 );

		float sinVal = sin( timef );
		int res = JayUtils::map( sinVal, -1.0, 1.0, 0, 255, true );
		std::cout << "sineWave " << res << std::endl;
	}
}
