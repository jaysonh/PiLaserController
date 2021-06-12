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
	
    		if(myFile_Handler.is_open())
    		{
        		// Keep reading the file
        		while(getline(myFile_Handler, myLine))
        		{
            			// print the line on the standard output
				jsonStr += myLine;
        		}
    			// File Close
    			myFile_Handler.close();
			
	                json::jobject jsonConfig = json::jobject::parse( jsonStr ); 

			laserSettings.blankWaitTime   = atoi( jsonConfig.get( "blankWaitTime"  ).c_str() );
			laserSettings.displayWaitTime = atoi( jsonConfig.get( "displayWaitTime").c_str() );
    			
			std::cout << "blankWaitTime: " << laserSettings.blankWaitTime << " displayWait: " << laserSettings.displayWaitTime << std::endl;
		}
    		else
    		{
        		cout << "Unable to open json the file!";
	    	}
	}
}
