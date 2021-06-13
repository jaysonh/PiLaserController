#include "Hardware.h"


namespace Hardware
{
	ADCDACPi adcdac;
	bool     threadRunning;

	int lastR = 0;
	int lastG = 0;
	int lastB = 0;

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
		int outR = _r;

		lastR = outR;
		if( laserBlank )
		{
			outR = 0;
		}		

		softPwmWrite(PinOut::redPin, outR);
	}

	void setLaserGrn( int16_t _g )
	{
		int outG = _g;
                
		lastG = outG;
		if( laserBlank )
                {
                        outG = 0;
                }

                softPwmWrite( PinOut::grnPin, outG );
	}

	void setLaserBlu( int16_t _b )
	{
		int outB = _b;
		lastB = outB;

		if( laserBlank )
		{
			outB = 0;
		}

		softPwmWrite( PinOut::bluPin, outB );
	}

        void setBlank( bool _state )
	{
		if( _state != laserBlank )
		{
			laserBlank = _state;
			std::cout << "setting blank: " << (int)laserBlank << std::endl;
			
			if( laserBlank )
			{
				setLaserCol( 0, 0, 0 ); // to update laser colours
			}else
			{
				setLaserCol( lastR, lastG, lastB );
			}
		}
	}
}
