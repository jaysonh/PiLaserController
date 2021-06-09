#include "CmdHandler.h"

namespace CmdHandler
{
	bool check( std::string _cmd )
	{
		for( auto c : CmdList::commands)
		{
			if (_cmd.rfind(c, 0) == 0) 
			{
  				// s starts with prefix
				std::cout << "found it ok"<< std::endl;
			}
		}

		return false;
	}
}
