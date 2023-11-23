#pragma once
#include "Integer.hpp"
#include "Instruction.hpp"
#include "ArithmeticInstructions.hpp"
#include "IOInstructions.hpp"
#include "CopyInstructions.hpp"
#include "BranchInstructions.hpp"
#include <map>
#include <string>

class CPU {
    Integer AC;
    unsigned int PC;
    Integer *memory;
    std::map<std::string, Instruction*> instruction_codes;
    unsigned int instruction_amount;
    bool running;

    public:
        CPU();
        void addToMemory(Integer value);
        bool execute();
        void updatePC();
        ~CPU();
        inline void setAC(Integer AC) { this->AC = AC; }
        inline Integer getAC() const { return AC; }
        inline std::string getStrMemoryAt(const int index) {return  (*(memory + index)).toString(); }
        inline bool isRunning() const {return running;}
        inline void setRunning(bool r) {running = r;}
        inline unsigned int getPC() const {return PC;}

        /* Retorna uma referencia para um endereco da memoria */
        inline Integer* getAddress(const int index) { return memory + index;}
};