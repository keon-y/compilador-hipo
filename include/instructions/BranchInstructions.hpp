#pragma once
#include "Instruction.hpp"

class NoOperation : public Instruction {
    public:
        NoOperation() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class Branch : public Instruction {
    public:
        Branch() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class BranchPositive : public Instruction {
    public:
        BranchPositive() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class BranchPositiveOrZero : public Instruction {
    public:
        BranchPositiveOrZero() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class BranchNegative : public Instruction {
    public:
        BranchNegative() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class BranchNegativeOrZero : public Instruction {
    public:
        BranchNegativeOrZero() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class BranchNotZero : public Instruction {
    public:
        BranchNotZero() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class BranchZero : public Instruction {
    public:
        BranchZero() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class BranchInfinite : public Instruction {
    public:
        BranchInfinite() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};

class BranchNotInfinite : public Instruction {
    public:
        BranchNotInfinite() : Instruction() {};
        void execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) override;
};