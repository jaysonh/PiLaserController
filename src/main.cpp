#include <iostream>
#include <wiringPi.h>
#include "PWMGenerator.h"
#include <softPwm.h>
#include "pinOut.h"
#include "Hardware.h"

using namespace std;
using namespace ABElectronics_CPP_Libraries;

int main()
{
	// setup
	Hardware::setup();

	//ADCDACPi adcdac;
	
	// main loop
	while( true )
	{
		int v = PWMGenerator::sineWave( 5.00, 1.0, 0, 4096 );

		//adcdac.set_dac_raw( v, PinOut::xPin );
		//adcdac.set_dac_raw( v, PinOut::yPin );
	}


	return 0;
}
