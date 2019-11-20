#ifndef PROCESS_H
#define PROCESS_H

#include <vector>

#include "types.h"

class VM;

class Process
{
public:
    Process(int id, const std::string &filename);

    void loadProcess(VM &vm);
    void saveProcess(VM &vm);
    void endProcess(VM &vm);

    int id;
    size_t size;
    WORD initialPc = 0;
    BYTE ac = 0;
    WORD pc = 0;
    bool switchAddrMode = false;
    WORD offset = 0;
    std::vector<Block> blocks;


};

#endif // PROCESS_H
