#pragma once

#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>

namespace CmdList
{
	struct Cmd
	{
		Cmd( std::string _name, int (*_function)(int *, int ) )
		{
			name     = _name;
			function = _function;
		}
		std::string name;
		int (*function)(int *, int );
	};

 	extern std::vector< Cmd > commands; 
	extern int exitApp( int * _args, int numArgs );
	extern void setup();
}
