#pragma once

#include "Hardware.h"
#include "P2.h"
#include "ConfigLoader.h"

namespace RenderLoop
{
	const uint16_t MAX_NUM_POINTS    = 100;
	const uint16_t CENTER_MIRROR_ADX = 2047;
	const uint16_t CENTER_MIRROR_ADY = 2047;

	extern void   setDisplayBuffer( const P2 *ptrBlueprint, uint16_t _sizeBlueprint );	
	extern void * update( void * ); // main loop that sends to the laser
	extern void   init();

	extern bool	 threadRunning;
	extern bool     needSwapFlag;
	extern uint16_t newSizeBufferDisplay; // no need to be volatile
	extern uint16_t readingHead;

	// The following variables must be qualified volatile, as they may be modificated
	// outside the section of code where they appear [because of the ISR]
	extern P2 *ptrCurrentDisplayBuffer, *ptrHiddenDisplayBuffer;
	extern uint16_t sizeBufferDisplay;
	extern bool resizeFlag;

	extern LaserCol lastCol;
}
