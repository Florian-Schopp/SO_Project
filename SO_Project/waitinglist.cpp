#include "stdafx.h"
#include "waitinglist.h"

WaitingList::WaitingList()
{

}

void WaitingList::addProcess(const Process &process, VM &vm)
{
	processes.push_back(process);
	if (processes.size() == 1)
		vm.restoreContext(process);
}