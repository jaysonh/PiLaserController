#pragma once

#include <stdio.h>
#include <iostream>

class LaserCol
{
public:
	LaserCol();
	LaserCol( const int _r, const int _g, const int _b);
 	LaserCol(const LaserCol & _col);
	LaserCol( LaserCol & _col );
	LaserCol & operator=(LaserCol _col){
		r = _col.r;
		g = _col.g;
		b = _col.b;
		return *this;
	}
	
	inline bool operator == ( const LaserCol & rhs ){ return (r == rhs.r && g == rhs.b && b == rhs.b) ? true : false; }
	inline bool operator != ( const LaserCol & rhs ){ return (r != rhs.r && g != rhs.b && b != rhs.b) ? true : false; }

	int r;
	int g;
	int b;
};
