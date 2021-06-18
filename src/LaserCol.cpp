#include "LaserCol.h"


	LaserCol::LaserCol() :  r{0}, g{0}, b{0}
        {
        }

       LaserCol::LaserCol( const int _r, const int _g, const int _b)  : r{ _r }, g{ _g }, b{ _b }
        {

        }

        LaserCol::LaserCol(const LaserCol & _col)
        {
                r = _col.r;
                g = _col.g;
                b = _col.b;
        }

	LaserCol::LaserCol( LaserCol & _col )
	{
		r = _col.r;
		g = _col.g;
		b = _col.b;
	}


