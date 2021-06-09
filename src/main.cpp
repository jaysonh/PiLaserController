#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread>
#include <iostream>
#include <wiringPi.h>
#include "PWMGenerator.h"
#include <softPwm.h>
#include "pinOut.h"
#include "Hardware.h"
#include <unistd.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include "TestSignal.h"
#include "CmdControl.h"

using namespace std;

int main()
{
	// set up named pipe for communication
	CmdControl::setup();

//	const char * myfifo = "/tmp/myfifo5";
  
    	// Creating the named file(FIFO)
    	// mkfifo(<pathname>, <permission>)
/*    	mkfifo(myfifo, 0666);
	char str1[80], str2[80];

	while(1)
	{
		int fd1 = open(myfifo,O_RDONLY);
        	int bytesRead = read(fd1, str1, 80);
		

		if( bytesRead > -1)
		{
			printf("text from pipe: %s numBytes: %i\n", str1, bytesRead);
        	}
		close(fd1);
		usleep(1000 * 1000);
	
	}
*/
	CmdControl::update();

	// setup
	Hardware::setup();

	//thread laserThread( Hardware::update );
	//thread updateThread( TestSignal::update );
	
    	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

	while( true )
	{
		TestSignal::update();
	}
	
	return 0;
}
