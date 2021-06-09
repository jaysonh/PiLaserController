#include "Hardware.h"


namespace Hardware
{
	ADCDACPi adcdac;
	bool     threadRunning;
	
	void setup()
	{

        	wiringPiSetup();
		
		//pinMode( PinOut::redPin, OUTPUT );
		//pinMode( PinOut::grnPin, OUTPUT );
		//pinMode( PinOut::bluPin, OUTPUT );

        	softPwmCreate( PinOut::redPin, 0, PinOut::pwmRange );
        	softPwmCreate( PinOut::grnPin, 0, PinOut::pwmRange );
	        softPwmCreate( PinOut::bluPin, 0, PinOut::pwmRange );

		if (adcdac.open_dac() != 1)
        	{
                	std::cout << "cannot open adc" << std::endl;
                	return;
        	}
        	// Set the DAC gain to 1 which will give a voltage range of 0 to 2.048V.
        	adcdac.set_dac_gain(1);

		threadRunning = true;
	}

	void update()
	{
		while ( threadRunning )
		{

		}
	}


	void setLaserPos( int16_t x, int16_t y )
	{
		adcdac.set_dac_raw( x, PinOut::xPin );
                adcdac.set_dac_raw( y, PinOut::yPin );
		
        	if ( pointDelay > 0 ) usleep( pointDelay );
	
	}

	void setLaserCol( int16_t r, int16_t g, int16_t b )
	{
		//digitalWrite( PinOut::redPin, r );
		//digitalWrite( PinOut::grnPin, g );
		//digitalWrite( PinOut::bluPin, b );
		setLaserRed( r );
		setLaserGrn( g );
		setLaserBlu( b );
	}

	void setLaserRed( int16_t r )
	{
		softPwmWrite( PinOut::redPin, r );
	}

	void setLaserGrn( int16_t g )
	{
		softPwmWrite( PinOut::grnPin, g );
	}

	void setLaserBlu( int16_t b )
	{
		softPwmWrite( PinOut::bluPin, b );
	}
}
