#pragma once
#include "Instruction.hpp"

class Add : public Instruction {
    public:
        Add(std::string code) : Instruction(code) {};
        void execute(unsigned int& pc) override;
};

class Subtract : public Instruction {
    public:
        Subtract(std::string code) : Instruction(code) {};
        void execute(unsigned int& pc) override;
};

class Multiply : public Instruction {
    public:
        Multiply(std::string code) : Instruction(code) {};
        void execute(unsigned int& pc) override;
};

class Divide : public Instruction {
    public:
        Divide(std::string code) : Instruction(code) {};
        void execute(unsigned int& pc) override;
};

class Module : public Instruction {
    public:
        Module(std::string code) : Instruction(code) {};
        void execute(unsigned int& pc);
};