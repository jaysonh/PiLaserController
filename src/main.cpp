#include <iostream>
#include <wiringPi.h>
#include "PWMGenerator.h"

int main()
{

	wiringPiSetup();

	while( true )
	{
		std::cout << "Hello World" << std::endl;
		PWMGenerator::sineWave( 2.0, 1.0, 0, 255, 1 );
	}

	return 0;
}
