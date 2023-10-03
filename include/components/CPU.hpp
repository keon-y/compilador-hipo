#pragma once
#include "Integer.hpp"
#include <vector>
#include "Instruction.hpp"

class CPU {
    Integer AC;
    unsigned int PC;
    std::vector<Instruction*> program;

    public:
        CPU();
        void addInstruction(Instruction* instruction);
        void executeProgram();
};