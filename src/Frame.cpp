#include "Frame.h"

void Frame::addPoint( P2 & p )
{
	if(numPoints < MAX_POINTS )
	{
		loadBuff[ numPoints ] = p;
		numPoints++;
	}
}



void Frame::clear()
{
	numPoints = 0;
}

