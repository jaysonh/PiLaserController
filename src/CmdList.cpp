#include "CmdList.h"


namespace CmdList
{
	std::vector< Cmd > commands;

	void setup()
	{
		commands.push_back( Cmd("exit",   &CmdList::exitApp ));
		commands.push_back( Cmd("setCol", &CmdList::setCol  ));
		commands.push_back( Cmd("blank",  &CmdList::setBlank   ));
	}

	int exitApp( int *_args, int _numArgs )
	{
		// stop the hardware running
		Hardware::close();
		
		// stop the communication listener
		CmdControl::closeComm();

		// hard exit the application
		exit(EXIT_FAILURE);
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
}
