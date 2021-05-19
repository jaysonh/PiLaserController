#include "Hardware.h"


namespace Hardware
{
	ADCDACPi adcdac;

	void setup()
	{

        	wiringPiSetup();

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

	}

	void update()
	{

	}


	void setLaserPos( int16_t x, int16_t y )
	{
		adcdac.set_dac_raw( x, PinOut::xPin );
                adcdac.set_dac_raw( y, PinOut::yPin );
	}

	void setLaserCol( uint8_t r, uint8_t g, uint8_t b )
	{
		setLaserRed( r );
		setLaserGrn( g );
		setLaserBlu( b );
	}

	void setLaserRed( uint8_t r )
	{
		softPwmWrite( PinOut::redPin, 125 );
	}

	void setLaserGrn( uint8_t g )
	{
		softPwmWrite( PinOut::grnPin, 125 );
	}

	void setLaserBlu( uint8_t b )
	{
		softPwmWrite( PinOut::bluPin, 125 );
	}
}
