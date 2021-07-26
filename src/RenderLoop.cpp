
#include "RenderLoop.h"

namespace RenderLoop
{
	P2 displayBuffer1[ MAX_NUM_POINTS ];
	P2 displayBuffer2[ MAX_NUM_POINTS ];

	LaserCol lastCol  (0,0,0);
	LaserCol blankCol (0,0,0);

	bool 	threadRunning = true;

	P2 	* ptrCurrentDisplayBuffer, *ptrHiddenDisplayBuffer;
	uint16_t 	  readingHead, newSizeBufferDisplay; // no need to be volatile
	uint16_t sizeBufferDisplay;
	bool     needSwapFlag;

	void setDisplayBuffer( const P2 * _ptrFrameBuffer, uint16_t _size )
	{
		// note: can I use memcpy with size(P2)?? probably yes and much faster... TP TRY!!
  		//memcpy (ptrHiddenDisplayBuffer, _ptrFrameBuffer, _size*sizeof(P2));
  		//uploadedBuffer = new P2[ _size ];
  		for (uint16_t k = 0; k < _size; k++)
  		{
    			ptrHiddenDisplayBuffer[k].x           = (int)_ptrFrameBuffer[k].x;
    			ptrHiddenDisplayBuffer[k].y           = (int)_ptrFrameBuffer[k].y;
			ptrHiddenDisplayBuffer[k].col.r       = _ptrFrameBuffer[k].col.r;
			ptrHiddenDisplayBuffer[k].col.g       = _ptrFrameBuffer[k].col.g;
			ptrHiddenDisplayBuffer[k].col.b       = _ptrFrameBuffer[k].col.b;
    			ptrHiddenDisplayBuffer[k].blank       = _ptrFrameBuffer[k].blank;
  		}
		std::cout << "setDisplayBuffer: " << _size << std::endl;

  		needSwapFlag = true;
 	 	//ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
  		//{
    			newSizeBufferDisplay = _size;
  		//}
	}

	void init()
	{
  		for (uint16_t i = 0; i < MAX_NUM_POINTS; i++)
  		{
    			displayBuffer1[i] = P2(CENTER_MIRROR_ADX, CENTER_MIRROR_ADY);
    			displayBuffer2[i] = P2(CENTER_MIRROR_ADX, CENTER_MIRROR_ADY);
  		}

  		sizeBufferDisplay = newSizeBufferDisplay = 0;

  		ptrCurrentDisplayBuffer = &(displayBuffer1[0]); // Note: displayBuffer1 is a const pointer to
  		// the first element of the array displayBuffer1[].
  		ptrHiddenDisplayBuffer = &(displayBuffer2[0]);
 	 	readingHead = 0;
 		needSwapFlag = false;
	}

	void * update( void * )
	{
		while( threadRunning )
		{
			// swap the display data if required
			if (needSwapFlag)
			{
				if( newSizeBufferDisplay != 0 && readingHead != 0 )
    					readingHead = (readingHead % newSizeBufferDisplay);
				else
					readingHead = 0;

    				// * NOTE : The following variables are volatile - they
	    			//   need to be, because they are modified in the ISR:
    				sizeBufferDisplay = newSizeBufferDisplay;

    				P2 *ptrAux = ptrCurrentDisplayBuffer;
    				ptrCurrentDisplayBuffer = ptrHiddenDisplayBuffer;
    				ptrHiddenDisplayBuffer  = ptrAux;

	    			needSwapFlag = false;
				//Hardware::setLaserCol( 255, 0, 0 );
				Hardware::setBlank( false );
			
  			}	
	
		
			if(sizeBufferDisplay > 0)
			{		
				// draw current point
				float adcX = static_cast<float>((ptrCurrentDisplayBuffer + readingHead)->x);
    				float adcY = static_cast<float>((ptrCurrentDisplayBuffer + readingHead)->y);	
		
				int r = static_cast<int16_t>((ptrCurrentDisplayBuffer + readingHead)->col.r);
				int g = static_cast<int16_t>((ptrCurrentDisplayBuffer + readingHead)->col.g);
				int b = static_cast<int16_t>((ptrCurrentDisplayBuffer + readingHead)->col.b); 
 
				LaserCol col(r,g,b);
				//std::cout << col.r <<","<< col.g <<"," << col.b << std::endl;
    				if( !(lastCol.r == col.r && lastCol.g == col.g && lastCol.b == col.b) )
				{
					//std::cout << "setting col: " << col.r << ","<<col.g << ","<<col.b<< std::endl;
					Hardware::setLaserCol( col );
					usleep( 10 ); // wait 10 us to change laser state
				}
				lastCol = col;
				Hardware::setLaserPos((int)adcX, (int)adcY);
				usleep(ConfigLoader::laserSettings.displayWaitTime);

				// move to next point
				//readingHead = (readingHead + 1) % sizeBufferDisplay;

				// turn laser back on if first pos				
				if ( readingHead == 0)
				{
					//Hardware::setLaserCol( col );
					//usleep( 20 );
				}
				readingHead++;
				
				// turn laser off if last pos
				if(readingHead >= sizeBufferDisplay)
				{
					readingHead = 0;
					// blank at end
					//Hardware::setLaserCol( blankCol );
					//usleep( 20 );
				}
			}

			//usleep(ConfigLoader::laserSettings.displayWaitTime);
		}
		// Make sure to turn laser off at the end
		Hardware::setLaserCol( 0, 0, 0 );

		return NULL;
	}
}
