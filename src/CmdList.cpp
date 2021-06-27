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

			std::cout << "col: " << r << "," << g << "," << b << std::endl;
			Renderer2D::clearBlueprint();
			for( int i = 3; i < numArgs; i += 2 )
			{
				int x = _args[i];
				int y = _args[i+1];
				
				P2 p(x, y, r, g, b, false);
				Renderer2D:: addToBlueprint( p );				
				std:: cout << "point: " << x << "," << y << std::endl;	

			}
			Renderer2D::renderFigure();
			// now send points to the laser renderer
                                                                                                                                                                                                                         extern const P2 getLastPoint();
			
		}

		return 0;
	}

	int restartApp( int * _args, int numArgs )
	{
		AppControl::restart();
		return 0;
	}
}
