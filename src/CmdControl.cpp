#include "CmdControl.h"

namespace CmdControl
{
        const char * myfifo = "/tmp/laserControl";
        //const char * myfifo = "/var/www/html/laserControl";
	const int    SLEEP_TIME = 1000000;
        const int    MAX_COMMAND_LENGTH = 80;
	
	bool threadRunning = true;

	void setup()
	{
		CmdList::setup();
		mkfifo(myfifo, 0666);
		// need to reset write permission her
		// otherwise other users don't have write permission not sure why?
		chmod(myfifo, 0666 );
		threadRunning = true;
	}

	void closeComm()
	{
		threadRunning = false;
		std::remove( myfifo );
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
				std::cout << "recv numBytes: " << bytesRead << " cmd: " << commandInput  << "#" << std::endl; 

				CmdHandler::check( cmdStr );
			}

			memset( commandInput, 0, sizeof commandInput );
			
			close( fd1 );
			usleep( 1000 * 1000 );
		}

		return NULL;
	}
}

