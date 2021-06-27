#include "AppControl.h"

namespace AppControl
{

	void restart()
	{
		// write a file called .restart which will be picked up a by a script that will restart the app
		ofstream file;
    		file.open ( restartFilePath, ios::out);
		file.close();

		exitApp();
	}

	void exitApp()
	{
 		// stop the hardware running
                Hardware::close();

                // stop the communication listener
                CmdControl::closeComm();                                                                                                                                                                         
                // hard exit the application
                exit(EXIT_FAILURE);
	}
}
