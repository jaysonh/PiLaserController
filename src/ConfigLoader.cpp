#include "ConfigLoader.h"

using namespace std;

namespace ConfigLoader
{
	const std::string configFileName = "data/config.json";
	LaserSettings laserSettings;

	void load( std::string _file )
	{

		ifstream myFile_Handler;
    		string myLine;
		std::string jsonStr = "";

    		// File Open in the Read Mode
    		myFile_Handler.open( _file );
	
    		if( myFile_Handler.is_open() )
    		{
        		// read the file and store it in a string
        		while(getline(myFile_Handler, myLine))
        		{
				jsonStr += myLine;
        		}

    			myFile_Handler.close();
			
	                json::jobject jsonConfig = json::jobject::parse( jsonStr ); 

			laserSettings.blankWaitTime   = atoi( jsonConfig.get( "blankWaitTime"  ).c_str() );
			laserSettings.displayWaitTime = atoi( jsonConfig.get( "displayWaitTime").c_str() );
    			
		}
    		else
    		{
        		cout << "Unable to open json the file: " << _file << endl;
	    	}
	}
}
