#pragma once
#include "Integer.hpp"

class Instruction {
    public:
        Instruction();
        virtual void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) = 0;
};