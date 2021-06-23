#include "CmdHandler.h"

namespace CmdHandler
{
	bool check( std::string _cmd )
	{
		for( auto c : CmdList::commands)
		{
			if (_cmd.rfind(c.name, 0) == 0) 
			{
				std::cout << "foundcmd: " << c.name << endl; 
				std::vector <int> argList;
				JString::splitInt(_cmd, argList, ',');
				
				const int numArgs = argList.size() - 1;
				int args[ numArgs ];
				std::copy(argList.begin()+1, argList.end(), args);
					
				c.function(args, numArgs);
			}
		}

		return false;
	}
}
