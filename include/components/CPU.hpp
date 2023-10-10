#pragma once
#include "Integer.hpp"
#include "Instruction.hpp"
#include "ArithmeticInstructions.hpp"
#include "IOInstructions.hpp"
#include <map>
#include <string>

class CPU {
    Integer AC;
    unsigned int PC;
    Integer *memory;
    std::map<std::string, Instruction*> instruction_codes;
    unsigned int instruction_amount;

    public:
        CPU();
        void addToMemory(Integer value);
        void executeProgram();
        void updatePC();
        ~CPU();
        inline void setAC(Integer AC) { this->AC = AC; }
        inline Integer getAC() const  { return AC; }

        /* Retorna uma referencia para um endereco da memoria */
        inline Integer* getAddress(const int index) { return memory + index;}
};