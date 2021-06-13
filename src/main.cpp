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
#include <pthread.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <signal.h> 
#include "TestSignal.h" 
#include "CmdControl.h"
#include "ConfigLoader.h"

using namespace std;

int main()
{
	ConfigLoader::load();

	// set up named pipe for control communication
	CmdControl::setup();

	// setup the hardware
	Hardware::setup();

	// Start the communication thread
	pthread_t  commThread;
	pthread_create( &commThread, NULL, CmdControl::update, NULL);

	// Start the laser thread
	pthread_t laserThread;
	pthread_create( &laserThread, NULL, TestSignal::update, NULL);

	// on finish close the threads
	pthread_join( commThread,  NULL );
	pthread_join( laserThread, NULL );	

	// shutdown the hardware
	Hardware::close();
	
	return 0;
}
