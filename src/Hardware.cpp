#include "Hardware.h"


namespace Hardware
{
	ADCDACPi adcdac;
	bool     threadRunning;

	int r = 0;
	int g = 0;
	int b = 0;
	bool laserBlank = true;
	
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

		threadRunning = true;
		
		// set colour to off at start
		setLaserCol( 0, 0, 0 );
		setBlank( true );
	}

	void update()
	{
		while ( threadRunning )
		{

		}
	}

	void close()
	{

		setLaserCol( 0, 0, 0 );
		setLaserPos( laserCentreX, laserCentreY );

		// wait a little for the hardware to update
		usleep(1000 * 1000);

		threadRunning = false;
	}

	void setLaserPos( int16_t x, int16_t y )
	{
		adcdac.set_dac_raw( x, PinOut::xPin );
                adcdac.set_dac_raw( y, PinOut::yPin );
		
        	if ( pointDelay > 0 ) usleep( pointDelay );
	}

	void setLaserCol( int16_t r, int16_t g, int16_t b )
	{
		setLaserRed( r );
		setLaserGrn( g );
		setLaserBlu( b );
	}

	void setLaserRed( int16_t _r )
	{
		r = _r;
		softPwmWrite( PinOut::redPin, r );
	}

	void setLaserGrn( int16_t _g )
	{
		g = _g;
		softPwmWrite( PinOut::grnPin, g );
	}

	void setLaserBlu( int16_t _b )
	{
		b = _b;
		softPwmWrite( PinOut::bluPin, b );
	}

        void setBlank( bool _state )
	{
		if( _state != laserBlank )
		{
			laserBlank = _state;
			
			if( laserBlank )
				setLaserCol( 0, 0, 0 );
			else
				setLaserCol( r, g, b );
		}
	}
}
