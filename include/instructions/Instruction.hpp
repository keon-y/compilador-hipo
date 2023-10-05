#pragma once
#include <string>
#include <map>
#include "Integer.hpp"

class Instruction {
    public:
        Instruction();
        virtual void execute(unsigned int& pc, Integer num) = 0;
};