#include "stdafx.h"
#include "readylist.h"

ReadyList::ReadyList()
{

}

bool ReadyList::hasProcess()
{
	return processes.size()>0;
}

void ReadyList::addProcess(const Process &process, VM &vm)
{
    processes.push_back(process);
    if (processes.size() == 1)
        vm.restoreContext(process);
}

VM::CycleResult ReadyList::evalProcess(VM &vm)
{
    if (currentActiveCicles < maxActiveCicles)
    {
        currentActiveCicles++;
    }
    else
    {
        currentActiveCicles = 0;
        if (processes.size() > 1)
        {
            Process proc = processes.front();
            processes.pop_front();
            vm.saveContext(proc);
            processes.push_back(proc);
            vm.restoreContext(processes.front());
        }
    }

    processes.front().loadProcess(vm);
	return vm.eval();
}

Process& ReadyList::removeCurrentProcess(VM &vm)
{
    currentActiveCicles = 0;
	Process p = processes.front();
	p.endProcess(vm);
    processes.pop_front();
	if (!processes.empty())
		vm.restoreContext(processes.front());
	return p;
}

Process &ReadyList::front()
{
    return processes.front();
}
