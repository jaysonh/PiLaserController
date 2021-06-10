#include "CmdControl.h"

namespace CmdControl
{
        const char * myfifo = "/tmp/laserControl";
        const int    SLEEP_TIME = 1000000;
        const int    MAX_COMMAND_LENGTH = 80;
	
	bool threadRunning = true;

	void setup()
	{
		CmdList::setup();
		mkfifo(myfifo, 0666);
		threadRunning = true;
	}

	void closeComm()
	{
		threadRunning = false;
	}

	void * update(void *)
	{
		while( threadRunning )
		{
			int fd1 = open( myfifo, O_RDONLY);
			char commandInput[ MAX_COMMAND_LENGTH ];
			int bytesRead = read(fd1, commandInput, MAX_COMMAND_LENGTH);

			if(bytesRead > -1 )
			{
				std::string cmdStr( commandInput );				
				printf("text from pipe: %s numBytes: %i\n", commandInput, bytesRead); 

				CmdHandler::check( cmdStr );
			}


			close( fd1 );
			usleep( 1000 * 1000 );
		}

		return NULL;
	}
}

