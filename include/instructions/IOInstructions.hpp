#pragma once
#include "Instruction.hpp"
#include <iostream>

class Read : public Instruction {
    public:
        Read() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class Print : public Instruction {
    public:
        Print() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};