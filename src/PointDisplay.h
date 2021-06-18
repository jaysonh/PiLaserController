#pragma once

#include "PWMGenerator.h"
#include "Hardware.h"
#include "Frame.h"
#include "Renderer2D.h"
#include "P2.h"

namespace PointDisplay
{
	extern void   init();
	extern void * update( void * );

	extern bool threadRunning;
}
