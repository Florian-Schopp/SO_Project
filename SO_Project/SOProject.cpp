#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>

#include "so.h"

int main()
{
	SO so;
	so.JobArrival("programs/renato/work500m.txt");
	so.JobArrival("programs/renato/n2.txt");
	//so.JobArrival("programs/renato/work500m.txt");
	so.JobArrival("programs/renato/n2.txt");
	int i;
	std::cin >> i; 
	return 0;
}