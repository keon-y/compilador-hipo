#pragma once
#include <string>
#include <map>
#include "Integer.hpp"

class Instruction {
    public:
        Instruction();
        virtual void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) = 0;
};