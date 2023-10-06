#pragma once
#include "Instruction.hpp"

class Add : public Instruction {
    public:
        Add() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class Subtract : public Instruction {
    public:
        Subtract() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class Multiply : public Instruction {
    public:
        Multiply() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class Divide : public Instruction {
    public:
        Divide() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class Module : public Instruction {
    public:
        Module() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num);
};