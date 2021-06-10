
#include "TestSignal.h"
#include <chrono>

namespace TestSignal
{
	bool threadRunning = true;

	void * update( void * )
	{
		Hardware::setLaserCol( 0, 0, 255 );

		while( threadRunning )
		{
			int x = PWMGenerator::sineWave( 20.1, 1.0, 0, 4096 );
			int y = PWMGenerator::cosWave ( 20.1, 1.0, 0, 4096 );
			Hardware::setLaserPos( x, y );
			
			usleep(10);			
		}

		return NULL;
	}

	void close()
	{
		threadRunning = false;
	}
}
