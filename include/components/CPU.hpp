#pragma once
#include "Integer.hpp"
#include "Instruction.hpp"
#include "ArithmeticInstructions.hpp"
#include <map>
#include <string>

class CPU {
    Integer AC;
    unsigned int PC;
    Integer *memory;
    std::map<std::string, Instruction*> instruction_codes;
    unsigned int instruction_amount;

    public:
        CPU();
        void addToMemory(Integer value);
        void executeProgram();
        ~CPU();
};