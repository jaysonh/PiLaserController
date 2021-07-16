#include "Renderer2D.h"

namespace Renderer2D {

// ======================= DEFAULT STATE VARIABLE DEFINITIONS  =======================
// NOTE: default parameters should be in a "defaultParameters" file (Json or XML?). For the
// time being, they are in Utils.h
P2 center(0,0);   // note (0,0) in "renderer" coordinates is the center of mirrors.
float angle = 0;
float scaleFactor = 1.0;
bool colorRed = true;
uint16_t numframeBufferPoints=0;
uint16_t sizeBlueprint = 0;   // this would not be necessary if using an STL container. It is
// just the size of the current bluepring array, modified and set when drawing a figure (see
// graphic primitives)

P2 bluePrintArray[RenderLoop::MAX_NUM_POINTS];  // PointBuffer bluePrintArray
P2 frameBuffer[RenderLoop::MAX_NUM_POINTS];     // the rendered, clipped points (do a P2i).
// NOTE: frameBuffer is an auxiliary LOCAL variable, we could write directly to the hidden display buffer,
// but this way we may have further processing done

uint16_t getSizeBlueprint() {
        return(sizeBlueprint);
}   // mainly for check

const P2 getLastPoint() {
        return(bluePrintArray[sizeBlueprint-1]);
}

void mapViewport(P2 &_point, float _minX, float _maxX, float _minY, float _maxY)
{
        _point.x = (_point.x - _minX) * (MAX_MIRRORS_ADX - MIN_MIRRORS_ADX) / (_maxX - _minX) + MIN_MIRRORS_ADX;
        // NOTE: the map function in arduino uses long(s), not floats!!
        _point.y = (_point.y - _minY) * (MAX_MIRRORS_ADY - MIN_MIRRORS_ADY) / (_maxY - _minY) + MIN_MIRRORS_ADY;
}
           

void addToBlueprint(const P2 &_newPoint) {


        // add point and increment index:
        if (sizeBlueprint < RenderLoop::MAX_NUM_POINTS)
        {
		bluePrintArray[sizeBlueprint++] = _newPoint;               
		
        } 
        // otherwise do nothing
        
	//bluePrintArray[sizeBlueprint].interaction( 1 );

}

bool clipLimits(P2 &_point)
{
	bool clipped = false;
	if (_point.x > MAX_MIRRORS_ADX)
	{
		_point.x = MAX_MIRRORS_ADX;
		clipped = true;
	}
	else if (_point.x < MIN_MIRRORS_ADX)
	{
		_point.x = MIN_MIRRORS_ADX;
		clipped = true;
	}
	if (_point.y > MAX_MIRRORS_ADY)
	{
		_point.y = MAX_MIRRORS_ADY;
		clipped = true;
	}
	else if (_point.y < MIN_MIRRORS_ADY)
	{
		_point.y = MIN_MIRRORS_ADY;
		clipped = true;
	}
	return (clipped);
}

// ======= RENDERING with CURRENT POSE TRANSFORMATION =====================================
void renderFigure() {
        // * NOTE: this needs to be called when changing the figure or number of points,
        // but also after modifying pose to avoid approximation errors.
               ;
        // Draw the figure with proper translation, rotation and scale on the "hidden" buffer:
        numframeBufferPoints = 0;
        for (uint16_t i = 0; i < sizeBlueprint; i++) 
        {
                P2 point(bluePrintArray[i]);

                mapViewport(point, minX, maxX, minY, maxY);                        
                
                if ( !clipLimits(point)  ) { // constrain to the galvo limits
                        
                        frameBuffer[numframeBufferPoints] = point;     
                        numframeBufferPoints++;
                }

        }

	// here we pass the points to the renderLoop
        RenderLoop::setDisplayBuffer(frameBuffer, numframeBufferPoints);
}

	void clearBlueprint() {
        	sizeBlueprint = 0;
        	renderFigure();
	}

	// save all points into a json file
	void savePoints( string filename )
	{
			
		//std::cout << "saving points" << std::endl;
		//json::JSON jsonObj;
		json::jobject jsonObj;

		jsonObj["numPoints"] = numframeBufferPoints;

		std::vector<json::jobject> points;
		
		for(int i = 0; i < numframeBufferPoints; i++)
		{
			stringstream si;
			si << i;
		
			std::string xStr = "x" + si.str();
			std::string yStr = "y" + si.str();

			jsonObj[xStr] = (int)frameBuffer[i].x;
			jsonObj[yStr] = (int)frameBuffer[i].y;
			//json::jobject point;
			//point["x"] = (int)frameBuffer[i].x; // problem saving floats?
			//point["y"] = (int)frameBuffer[i].y; // problem saving floats?
			//points.push_back( point );
		}
			
		//jsonObj["points"] = points;

		std::string serial = (std::string)jsonObj;

		ofstream myfile ( filename );
  		
		if (myfile.is_open())
  		{
			myfile << serial << endl;			

    			myfile.close();
  		}                
	}		

	void loadPoints( string filename)
	{
		 ifstream myFile_Handler;
                string myLine;
                std::string jsonStr = "";

                // File Open in the Read Mode
                myFile_Handler.open( filename );

                if( myFile_Handler.is_open() )
                {
                        // read the file and store it in a string
                        while(getline(myFile_Handler, myLine))
                        {
                                jsonStr += myLine;
                        }

                        myFile_Handler.close();
		}
		
		json::jobject result = json::jobject::parse( jsonStr );

		int numPoints =  atoi( result.get( "numPoints"  ).c_str() );
		cout << "numPoints from json: " << numPoints << endl; //result["numPoints"] <<endl;

		//cout << "pointsStr: "<< result.get("points") <<endl;
		//json::jobject allPoints = result["points"];

		//cout << "retrieved points joson" <<endl;
		//cout << (std::string)allPoints << endl;
		//json::jtype::jarray pointsArr = 

		P2 newPoints[numPoints];
		for( int i = 0; i < numPoints; i++)
		{
			stringstream si;                                                                                                                                                                                                   si << i;                                                                                                                                                                                   
                        std::string xStr = "x" + si.str();
                        std::string yStr = "y" + si.str();

			int xPos = atoi( result.get(xStr).c_str() );
			int yPos = atoi( result.get(yStr).c_str() );

			newPoints[i].x = xPos;
			newPoints[i].y = yPos;
		}				

		if(numPoints > 0)
		{
			setPoints( newPoints, numPoints );
		}
	}

	void setPoints( const P2 * _points, int _numPoints)
	{
		clearBlueprint();

		for(int i = 0; i < _numPoints; i++)
		{
			frameBuffer[i] = _points[i];
			
		}
		numframeBufferPoints = _numPoints;
		RenderLoop::setDisplayBuffer( frameBuffer, numframeBufferPoints );
	}
}
