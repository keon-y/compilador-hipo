#include "CPU.hpp"
#include <iostream>

/* Construtor da CPU */
CPU::CPU() {
    AC = Integer();
    PC = 0;
    instruction_amount = 0;
    memory = new Integer[100];
    for (int i = 0; i < 100; i++)

    
    /* Inicializacao dos codigos */
    instruction_codes["21"] = new Add();
    instruction_codes["22"] = new Subtract();
    instruction_codes["23"] = new Multiply();
    instruction_codes["24"] = new Divide();
    instruction_codes["25"] = new Module();

}

void CPU::addToMemory(Integer value) {
    memory[instruction_amount++] = value;
}

void CPU::executeProgram(){
    while (PC < instruction_amount)
        /* 
        *   Pega o os dois primeiros digitos do codigo (que indica a intrucao)
        *   e busca no MAP `instruction_codes` a instrucao correspondente
        *   depois, executa a instrucao, passando o PC e a segunda parte do 
        *   inteiro armazenado
        */
        instruction_codes[(memory[PC]).getFirstHalf()]->execute(PC, memory[PC]);
}

CPU::~CPU(){
    instruction_codes.clear();
    delete [] memory;
}