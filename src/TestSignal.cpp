#include "TestSignal.h"

namespace TestSignal
{
	bool threadRunning = true;

	void update()
	{
		while( threadRunning )
		{
			int v = PWMGenerator::sineWave( 5.00, 1.0, 0, 4096 );
			Hardware::setLaserPos( v, v );

			std::cout << "v: " << v << std::endl;
		}
	}
}
