#include "LineDisplay.h"

namespace LineDisplay
{
        void   init( const P2 & _beg, const P2 & _end )
        {
	        Renderer2D::clearBlueprint();

		float length = JUtils::length( _beg.x, _beg.y, _end.x, _end.y );

		float segLen = 5.0;
		
		Renderer2D::addToBlueprint( _beg );
		for( float t = 0.0; t < length; t += length )
		{
			P2 p( JUtils::map( t, 0, length, _beg.x, _beg.y),
			      JUtils::map( t, 0, length, _beg.y, _beg.y), 255, 0, 0, false  );

			Renderer2D::addToBlueprint( p );
		}
		Renderer2D::addToBlueprint( _end );
                
		Renderer2D::renderFigure();
                Hardware::setBlank( false );
        }
	
}
