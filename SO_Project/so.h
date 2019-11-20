#ifndef SO_H
#define SO_H

#include "vm.h"
#include "readylist.h"
#include "waitinglist.h"

class SO
{
public:
    SO();
	void JobArrival(const std::string &file);
    void teste1();
    void teste2();
    void teste3();

private:
	void run();
	int idx = 0;
    VM vm;
	WaitingList waitingList;
    ReadyList readyList;
};

#endif // SO_H
