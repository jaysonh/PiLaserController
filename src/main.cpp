
#include <thread>
#include <iostream>
#include <wiringPi.h>
#include "PWMGenerator.h"
#include <softPwm.h>
#include "pinOut.h"
#include "Hardware.h"
#include <unistd.h>

#include "TestSignal.h"

using namespace std;

int main()
{
	// setup
	Hardware::setup();

	//ADCDACPi adcdac;
	
	thread laserThread( Hardware::update );
	thread updateThread( TestSignal::update );

	while( true )
	{

	}
	
	return 0;
}
