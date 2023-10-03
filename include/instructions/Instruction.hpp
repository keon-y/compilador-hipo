#pragma once
#include <string>
#include "Integer.hpp"

class Instruction {
    Integer code;

    public:
        Instruction(std::string code);
        virtual void execute(unsigned int& pc) = 0;
        Integer getCode();
};