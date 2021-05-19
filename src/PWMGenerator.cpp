#include "PWMGenerator.h"


namespace PWMGenerator
{
	int sineWave( const float   _period, 
   	              const float   _amplitude, 
		      const uint16_t _min, 
		      const uint16_t _max
		     )
	{
		struct timespec now;
		clock_gettime( CLOCK_REALTIME, &now );
		const struct tm * tms = localtime( &now.tv_sec );
		
		int sec =  now.tv_sec % 100000;
		int ms  = (int)now.tv_nsec / 1000000;
		
		float timef = (float)sec + ( (float)ms / 1000.0 );

		float sinVal = sin( timef * _period);
		
		return (int)JayUtils::map( sinVal, -1.0, 1.0, _min, _max );
		
		
				
	}
}
