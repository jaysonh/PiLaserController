
#include "PointDisplay.h"
#include <chrono>

namespace PointDisplay
{
	bool threadRunning = true;

	void   init()
	{
		Renderer2D::clearBlueprint();

		// setup a cirlce for test
		float r = 50.0;

		for( float a = 0.0; a < TWO_PI; a+= 0.1 )
		{
			P2 p( r * cos( a ), r * sin( a ) );
			p.col.r = 255;
			p.col.g = 0;
			p.col.b = 0;	
			p.blank = false;
			Renderer2D::addToBlueprint( p );
		}
		Renderer2D::renderFigure();
		Hardware::setBlank( false );
	}

	void * update( void * )
	{
		Hardware::setBlank( false );
		//Hardware::setLaserCol( 255, 0, 0 );

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
