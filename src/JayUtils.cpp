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

namespace JString
{
	int splitStr(const std::string &txt, std::vector<std::string> &strs, char ch)
	{
    		size_t pos = txt.find( ch );
    		size_t initialPos = 0;
    		strs.clear();

    		// Decompose statement
    		while( pos != std::string::npos ) 
		{
        		strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        		initialPos = pos + 1;

        		pos = txt.find( ch, initialPos );
    		}

    		// Add the last one
    		strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    		return strs.size();
	}

	int splitInt( const std::string &txt, std::vector <int> &intList, char ch)
	{
		std::vector <std::string>  strList;
		splitStr( txt, strList, ch );
		// convert strings to int and store 
		for( auto s : strList )
		{
			std::cout << "storing: " << s << std::endl;
			intList.push_back( atoi( s.c_str() ) );
		}

		return intList.size();
	}
}
