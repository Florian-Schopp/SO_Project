#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <list>

#include "process.h"
#include "vm.h"


class WaitingList
{
public:
	WaitingList();
	void addProcess(const Process &process, VM &vm);

private:
	std::list<Process> processes;
};

#endif // WAITINGLIST_H
