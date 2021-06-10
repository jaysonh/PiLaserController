#include "CmdList.h"

namespace CmdList
{
	std::vector< Cmd > commands;

	void setup()
	{
		commands.push_back( Cmd("exit", &CmdList::exitApp ));
	}

	int exitApp( int v )
	{
		exit(EXIT_FAILURE);
		return 0;
	}
}
