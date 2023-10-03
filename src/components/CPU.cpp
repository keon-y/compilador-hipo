#include "CPU.hpp"

/* Construtor da CPU */
CPU::CPU() {
    AC = Integer();
    PC = 0;
}


void CPU::addInstruction(Instruction* instruction) {
    program.push_back(instruction);
}

void CPU::executeProgram(){
    while (PC < program.size())
        (program.at(PC))->execute(PC);
}