#pragma once

#include "Hardware.h"
#include "CmdControl.h"

namespace AppControl
{
	const string restartFilePath = ".restart";
	extern void restart();
	extern void exitApp();
}
