#pragma once

#include "RenderLoop.h"
#include "JayUtils.h"
#include "P2.h"
#include "simpleson/json.h"
#include <iostream>
#include <fstream>

namespace Renderer2D 
{

const string   pointSaveFile = "points_saved.json";

const uint16_t MAX_MIRRORS_ADX = 4095;
const uint16_t MIN_MIRRORS_ADX = 0;
const uint16_t MAX_MIRRORS_ADY = 4095;
const uint16_t MIN_MIRRORS_ADY = 0;


// ======== STATE VARIABLES  ================
// a) Simplified OpenGL-like "state variables":
//  1)  Simplified, orthographic projection transformation:
// * Note 1: The following parameters define the "region of interest" and
// will be used to map the values from the added vertices to the
// mirror coordinates (using Arduino "map" method or a custom one).
// * NOTE 2: for the time being, these parameters are fixed;
const float minX = -100.0;
const float maxX =  100.0;
const float minY = -100.0;
const float maxY =  100.0;

// 2) the "modelview" matrix (translation, rotation and scaling):
extern uint16_t numframeBufferPoints;
extern P2 center;
extern float angle;
extern float scaleFactor;
extern bool colorRed; // TODO: make a proper color object/struct (not just on/off for the red)

	// b) Number of points. In the future, it would be more interesting to have a
	// "resolution" variable. The number of points should be always smaller
	// than MAX_NUM_POINTS:
	extern uint16_t sizeBlueprint; // don't forget to set it properly before
	// starting the display engine. Normally there is no pb: it is automatically
	// set while drawing figures, plus it has a default start value of 0 [extern
	// global variable definition]

	extern void mapViewport(P2 &_point, float _minX, float _maxX, float _minY, float _maxY);
	extern void clearBlueprint();
	extern uint16_t getSizeBlueprint();

	extern const P2 getLastPoint();
	extern bool clipLimits(P2 &_point);
	extern void addToBlueprint(const P2 &_newPoint);

	extern void renderFigure(); // render with current pose transformation

	extern void savePoints( string filename = pointSaveFile );

	//namespace { // "private"
		//extern PointBuffer bluePrintArray;
		extern P2 bluePrintArray[ RenderLoop::MAX_NUM_POINTS ];
	//}

} // end namespace

