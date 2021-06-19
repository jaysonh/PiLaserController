#include "PriorityManager.h"

namespace PriorityManager
{
	void setup()
	{
		int which = -19;//PRIO_PROCESS;
		id_t pid;
		int ret;

		pid = getpid();
		ret = getpriority(which, pid);
		std::cout << "pid: " << pid << " priority: " << ret << std::endl;
	}

	void *  update( void * )
	{
		return NULL;
	}
}
