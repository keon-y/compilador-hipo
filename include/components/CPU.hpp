#pragma once
#include "Integer.hpp"
#include "Instruction.hpp"
#include "ArithmeticInstructions.hpp"
#include "IOInstructions.hpp"
#include "CopyInstructions.hpp"
#include "BranchInstructions.hpp"
#include "ShiftInstructions.hpp"
#include <map>
#include <string>
#include <cstring>

class CPU {
    Integer AC;
    unsigned int PC;
    Integer *memory;
    Integer *memory_before; //armazenar memoria antes da execucao para poder executar mais de uma vez
    std::map<std::string, Instruction*> instruction_codes;
    unsigned int instruction_amount;
    bool running;
    bool loaded;

    public:
        CPU();
        void addToMemory(Integer value);
        int execute();
        void updatePC();
        ~CPU();
        inline void setAC(Integer AC) { this->AC = AC; }
        inline Integer getAC() const { return AC; }
        inline std::string getStrMemoryAt(const int index) {return  (*(memory + index)).toString(); }
        inline bool isRunning() const {return running;}
        inline void setRunning(bool r) {running = r;}
        inline bool isLoaded() {return loaded;}
        inline unsigned int getPC() const {return PC;}
        void resetMemory();
        void initializeMemory();

        /* Retorna uma referencia para um endereco da memoria */
        inline Integer* getAddress(const int index) { return memory + index;}
};