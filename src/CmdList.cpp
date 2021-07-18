#include "CmdList.h"


namespace CmdList
{
	std::vector< Cmd > commands;

	void setup()
	{
		commands.push_back( Cmd( "exit",     &CmdList::exitApp  ));
		commands.push_back( Cmd( "setCol",   &CmdList::setCol   ));
		commands.push_back( Cmd( "blank",    &CmdList::setBlank ));
		commands.push_back( Cmd( "addShape", &CmdList::addShape ));
		commands.push_back( Cmd( "restart",  &CmdList::restartApp ));
		commands.push_back( Cmd( "save",     &CmdList::savePoints ));
		commands.push_back( Cmd( "load",     &CmdList::loadPoints ));
	}

	int exitApp( int *_args, int _numArgs )
	{
		AppControl::exitApp();

		return 0;
	}

	int setBlank( int * _args, int numArgs )
	{
		std::cout << "setBlank numArgs: " << numArgs << endl;
		if( numArgs == 1 )
		{
			int blankState = _args[0];
			Hardware::setBlank( blankState );
		}

		return 0;
	}

	int setCol(int * _args, int numArgs )
	{
		if( numArgs >= 3 )
		{
			int r = _args[0];
			int g = _args[1];
			int b = _args[2];

			Hardware::setLaserCol( r, g, b );
		}

		return 0;
	}

	int addShape( int * _args, int numArgs )
	{

		if( numArgs > 4 )
		{
			int r = _args[0];
                        int g = _args[1];
                        int b = _args[2];

			int numPts = ( numArgs - 3 ) / 2;

			if(numPts > 0)
			{
				P2 points[ numPts ];			
				int ptIndx=0;	
				for( int i = 3; i < numArgs; i += 2 )
				{
					int x = _args[i];
					int y = _args[i+1];
				
					points[ptIndx++] = P2( x, y, r, g, b, false );
				}

				Renderer2D::clearBlueprint();

				for( int i = 1; i < numPts; i++ )
				{
					P2 p0 = points[ i - 1];
					P2 p1 = points[ i    ];
				
					float interpSize = 5.0;

    					float lineLength = sqrt( pow(p1.x - p0.x, 2) +  
        	                     				 pow(p1.y - p0.y, 2) * 1.0); 
					Renderer2D:: addToBlueprint( p0 );
					for( float t = 0.0; t <= lineLength; t += interpSize )
    					{
					        float x = JUtils::map( t, 0, lineLength, p0.x, p1.x );
					        float y = JUtils::map( t, 0, lineLength, p0.y, p1.y );

						P2 p ( x, y, r, g, b, false );
					
						Renderer2D:: addToBlueprint( p );
					}
					Renderer2D:: addToBlueprint( p1 );
					//P2 p(x, y, r, g, b, false);
                                	//Renderer2D:: addToBlueprint( p );
				}
				Renderer2D::renderFigure();
				// now send points to the laser renderer
                        }                                                                                                                                                                                                 extern const P2 getLastPoint();
			
		}

		return 0;
	}

	int restartApp( int * _args, int numArgs )
	{
		AppControl::restart();
		return 0;
	}

	int savePoints( int * _args, int numArgs )
	{
		Renderer2D::savePoints();
		
		return 0;
	}

	int loadPoints( int * _args, int numArgs )
	{
		Renderer2D::loadPoints();

		return 0;
	}
}
