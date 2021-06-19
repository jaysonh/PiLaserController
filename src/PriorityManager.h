#pragma once
#include <sys/resource.h>
#include <iostream>
#include <unistd.h>

namespace PriorityManager
{
	extern void setup();
	extern void * update( void * );
}
