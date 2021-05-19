#include <iostream>
#include <wiringPi.h>
#include "PWMGenerator.h"
#include "ABE_ADCDACPi.h"
#include <softPwm.h>
#include "pinOut.h"

using namespace std;
using namespace ABElectronics_CPP_Libraries;


int main()
{
	// setup
	wiringPiSetup();

	softPwmCreate( PinOut::redPin, 0, PinOut::pwmRange );
	softPwmCreate( PinOut::grnPin, 0, PinOut::pwmRange );
	softPwmCreate( PinOut::bluPin, 0, PinOut::pwmRange );

	ADCDACPi adcdac;
	
	std::cout << "setup wiring complete" << std::endl;
	
	if (adcdac.open_dac() != 1) 
	{
		std::cout << "cannot open adc" << std::endl;
		return(1);
	}
    	// Set the DAC gain to 1 which will give a voltage range of 0 to 2.048V.
    	adcdac.set_dac_gain(1);

	// main loop
	while( true )
	{
		int v = PWMGenerator::sineWave( 5.00, 1.0, 0, 4096 );

		adcdac.set_dac_raw( v, 1 );
		adcdac.set_dac_raw( v, 2 );
		
		softPwmWrite( PinOut::redPin, 125 );
	}


	return 0;
}
