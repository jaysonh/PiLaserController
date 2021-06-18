#pragma once

#include "P2.h"

#define MAX_POINTS 100

class Frame
{
public:

	void addPoint( P2 & p );
	void clear();
	
	int getNumPoints();

	P2 buffer0[ MAX_POINTS ];
	P2 buffer1[ MAX_POINTS ];

	P2 * drawBuff;
	P2 * loadBuff;
private:
	
	int numPoints;
};
