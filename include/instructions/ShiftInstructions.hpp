#pragma once
#include "Instruction.hpp"
#include <iostream>

class ShiftRight : public Instruction {
    public:
        ShiftRight() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class ShiftLeft : public Instruction {
    public:
        ShiftLeft() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};