#include "CmdHandler.h"

namespace CmdHandler
{
	bool check( std::string _cmd )
	{
		for( auto c : CmdList::commands)
		{
			if (_cmd.rfind(c.name, 0) == 0) 
			{
  				// s starts with prefix
				std::cout << "found: " << c.name << std::endl;
					
				std::vector <int> argList;
				JString::splitInt(_cmd, argList, ' ');
				
				const int numArgs = argList.size() - 1;
				int args[ numArgs ];
				std::copy(argList.begin()+1, argList.end(), args);
					
				std::cout << "numArgs: " << numArgs << std::endl;
				for( int i = 0; i < numArgs; i++ )
				{
					std::cout << "arg: " << args[i] << std::endl;
				}

				c.function(args, numArgs);
			}
		}

		return false;
	}
}
