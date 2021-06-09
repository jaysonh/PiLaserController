#include "JayUtils.h"

namespace JUtils
{

/*	float map( float _v, float _inMin, float _inMax, float _outMin, float _outMax, bool _clamp)
	{	
		float res = _outMin + (_outMax - _outMin) * ((_v - _inMin) / (_outMin - _inMin)) ;
		res = _clamp && res > _outMax ? _outMax : res;
		res = _clamp && res < _outMin ? _outMin : res;
 
		return res; 
	}

*/
	float map(float x, float in_min, float in_max, float out_min, float out_max) {
  		return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	}
}
