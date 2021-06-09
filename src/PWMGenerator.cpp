#include "PWMGenerator.h"


namespace PWMGenerator
{
	float sinVal = 0.0;

	int sineWave( const float   _period, 
   	              const float   _amplitude, 
		      const uint16_t _min, 
		      const uint16_t _max
		     )
	{
/*
		struct timespec now;
		clock_gettime( CLOCK_REALTIME, &now );
		const struct tm * tms = localtime( &now.tv_sec );
		
		int sec =  now.tv_sec % 100000;
		int ms  = (int)now.tv_nsec / 1000000;
		
		float timef = (float)sec + ( (float)ms / 1000.0 );

		//float t = ( fmod( timef, _period ) /_period ) * JMath::PI;
		float sinVal = sin( timef * _period );
*/
		sinVal += 0.1;		
		return (int)JUtils::map( sin(sinVal), -1.0, 1.0, _min, _max );
		
		
				
	}

	int cosWave ( const float   _period,
                      const float   _amplitude,
                      const uint16_t _min,
                      const uint16_t _max
                     )
        {
                /*
		struct timespec now;
                clock_gettime( CLOCK_REALTIME, &now );
                const struct tm * tms = localtime( &now.tv_sec );

                int sec =  now.tv_sec % 100000;
                int ms  = (int)now.tv_nsec / 1000000;

                float timef = (float)sec + ( (float)ms / 1000.0 );
		//float t = ( fmod( timef, _period ) /_period ) * JMath::PI;
                float cosVal = cos( timef * _period );
		*/

                return (int)JUtils::map( cos(sinVal), -1.0, 1.0, _min, _max );
        }
}
