#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "CmdHandler.h"

namespace CmdControl
{
	extern void setup();
	extern void * update(void *);
	extern void closeComm();

        extern const char * myfifo;// = "/tmp/laserControl";
        extern const int    SLEEP_TIME;// = 1000000;
        extern const int    MAX_COMMAND_LENGTH;// = 80;
	extern       bool   threadRunning;
}
