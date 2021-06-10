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
				c.function(0);
			}
		}

		return false;
	}
}
