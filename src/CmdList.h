#pragma once

#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "Hardware.h"

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

	extern void setup();

	// Each function which is run  needs to take a pointer to an int array and an int with the num arguments
	
	// exits the application and stops the laser running
	extern int exitApp( int * _args, int numArgs );
}
