#include "stdafx.h"
#include "so.h"

#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime> 
#include <array>
#include <future>
#include <thread>

std::thread SOThread;
std::chrono::steady_clock::time_point t0;

SO::SO()
{
	t0 = std::chrono::steady_clock::now();
	SOThread=std::thread(&SO::run, this);
	idx = 1;
}

void SO::JobArrival(const std::string &file)
{
	std::ifstream n2File(file);
	std::string exe = "";
	n2File >> exe;
	Process n2(idx, exe);
	std::chrono::duration<double> start = std::chrono::steady_clock::now() - t0;
	std::cout << "< " << start.count() << "><Job Arrival>< " << idx << "><Added to WaitingList>" << std::endl;
	idx++;
	readyList.addProcess(n2, vm);
}

void SO::run()
{
	while (true)
	{
		if (readyList.hasProcess()) {
			if (readyList.evalProcess(vm) == VM::CycleResult::finished)
			{
				int id=readyList.removeCurrentProcess(vm).id;
				std::chrono::duration<double> start = std::chrono::steady_clock::now() - t0;
				std::cout << "< " << start.count() << "><Job Ended>< " << id << "><Deleted from ReadyList>" << std::endl;
			}
				
		}
	}
	
}
