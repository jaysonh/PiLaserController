#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "LaserSettings.h"
#include "simpleson/json.h"

namespace ConfigLoader
{
	extern const std::string   configFileName;
	extern       LaserSettings laserSettings;

	extern void load( std::string _file = configFileName );
}
