#pragma once
#include "Instruction.hpp"

class CopyEA : public Instruction {
    public:
        CopyEA() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class CopyAE : public Instruction {
    public:
        CopyAE() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};