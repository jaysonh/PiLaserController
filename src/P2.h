#ifndef _P2_H
#define _P2_H

#include <cmath>
#include "JayUtils.h"
#include "LaserCol.h"

using namespace JMath;

class P2;
// Very simple 2D vector class:
class P2 {
    public:

    P2(): x(0), y(0) 
    {
    }

    P2(const float _x, const float _y) {
      x = _x;
      y = _y;
      blank   = false;
    }

    P2(const float _x, const float _y, const int _r, const int _g, const int _b, const bool _blank) {

      x = _x;
      y = _y;
      blank = _blank;
      col = LaserCol( _r, _g, _b );
    }

    P2(const P2& _point) {
      x     = _point.x;
      y     = _point.y;
      blank = _point.blank;
      col   = _point.col;
    }
 

    bool operator == (const P2 & p)
    {
      if(p.x == this->x && p.y == this->y)
        return true;
      else 
        return false;
    }

    bool operator != (const P2 & p)
    {
      if(p.x != this->x || p.y != this->y)
        return true;
      else 
        return false;
    }

    // Important: to use this as the RingBuffer type, we NEED to define the assignement operator
    inline void operator=( const P2& _point ) {
 	x = _point.x;
        y = _point.y;
        blank = _point.blank;
        col = _point.col;
    }


    inline void set(float _x, float _y) {
      x = _x;
      y = _y;
    }
    inline void set(const P2& _point) {
      x = _point.x;
      y = _point.y;
      blank       = _point.blank;
      col = _point.col;
    }

    // Transfom points (do not modify points in the "moldBuffer" it to avoid approximation drifts!)
    // Note: we don't care very much about the time it takes to do this, it is only done
    // when "moving" the current figure, not during ISR-based displaying.
    inline void translate(P2& _center) {
      x += _center.x;
      y += _center.y;
    }

    inline void rotate(float _angle) {
      float auxX = x;
      x = 1.0*x * cos(DEG_TO_RAD * _angle) - 1.0*y * sin(DEG_TO_RAD * _angle);
      y = 1.0*auxX * sin(DEG_TO_RAD * _angle) + 1.0*y * cos(DEG_TO_RAD * _angle);
    }

    inline void scale(float _factor) {
      x *= _factor;
      y *= _factor;
    }
    LaserCol col;

    bool  blank;
    float x, y;
};

#endif
