#include "CmdList.h"

namespace CmdList
{
	std::vector< Cmd > commands;

	void setup()
	{
		commands.push_back( Cmd("exit", &CmdList::exitApp ));
	}

	int exitApp( int *_args, int _numArgs )
	{
		exit(EXIT_FAILURE);
		return 0;
	}
}
