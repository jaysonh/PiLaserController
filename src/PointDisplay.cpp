
#include "PointDisplay.h"
#include <chrono>

namespace PointDisplay
{
	bool threadRunning = true;

	void   init()
	{
		Renderer2D::clearBlueprint();

		// setup a cirlce for test
		/*float r = 50.0;

		for( float a = 0.0; a < TWO_PI; a+= 0.1 )
		{
			P2 p( r * cos( a ), r * sin( a ) );
			p.col.r = 255;
			p.col.g = 0;
			p.col.b = 0;	
			p.blank = false;
			Renderer2D::addToBlueprint( p );
		}*/

		// draw a square
		bool blank = false;
		P2 squarePoints[20];
		squarePoints[0] = P2( -20, -20, 255,0,0, blank );
		squarePoints[1] = P2( -10, -20, 255,0,0, blank );
		squarePoints[2] = P2(   0, -20, 255,0,0, blank );
		squarePoints[3] = P2(  10, -20, 255,0,0, blank );
		squarePoints[4] = P2(  20, -20, 255,0,0, blank );

		squarePoints[5] = P2( 20, -20, 255,0,0, blank );
		squarePoints[6] = P2( 20, -10, 255,0,0, blank );
		squarePoints[7] = P2( 20,   0, 255,0,0, blank );
		squarePoints[8] = P2( 20,  10, 255,0,0, blank );
		squarePoints[9] = P2( 20,  20, 255,0,0, blank );

		squarePoints[10] = P2(  20, 20, 255,0,0, blank );
		squarePoints[11] = P2(  10, 20, 255,0,0, blank );
		squarePoints[12] = P2(  0,  20, 255,0,0, blank );
		squarePoints[13] = P2( -10, 20, 255,0,0, blank );
		squarePoints[14] = P2( -20, 20, 255,0,0, blank );
		
		squarePoints[15] = P2( -20,  20, 255,0,0, blank ); 
		squarePoints[16] = P2( -20,  10, 255,0,0, blank ); 
		squarePoints[17] = P2( -20,   0, 255,0,0, blank ); 
		squarePoints[18] = P2( -20, -10, 255,0,0, blank ); 
		squarePoints[19] = P2( -20, -20, 255,0,0, blank ); 

		for(int i = 0; i < 20;i++)
			Renderer2D::addToBlueprint( squarePoints[i] );

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
