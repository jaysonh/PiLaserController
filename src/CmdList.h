#pragma once

#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "Hardware.h"
#include "CmdControl.h"
#include "Renderer2D.h"
#include "AppControl.h"

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
	
	// set colour of the laser
	extern int setCol(int * _args, int numArgs ); // 0-red 1-green 2-blue

	extern int setBlank( int * _args, int numArgs); // 

	extern int addShape( int * _args, int numArgs );

	extern int restartApp( int * _args, int numArgs );

	extern int savePoints( int * _args, int numArgs );

	extern int loadPoints( int * _args, int numArgs );
}
