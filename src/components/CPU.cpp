#include "CPU.hpp"

/* Construtor da CPU */
CPU::CPU() {
    loaded = false;
    AC = Integer();
    PC = 0;
    instruction_amount = 0;
    memory = new Integer[100];
    memory_before = new Integer[100];

    /* Inicializacao dos codigos */
    instruction_codes["11"] = new CopyEA();
    instruction_codes["12"] = new CopyAE();

    instruction_codes["21"] = new Add();
    instruction_codes["22"] = new Subtract();
    instruction_codes["23"] = new Multiply();
    instruction_codes["24"] = new Divide();
    instruction_codes["25"] = new Module();

    //instruction_codes["31"] = new Read();
    //instruction_codes["41"] = new Print();

    instruction_codes["50"] = new NoOperation();
    instruction_codes["51"] = new Branch();
    instruction_codes["52"] = new BranchPositive();
    instruction_codes["53"] = new BranchPositiveOrZero();
    instruction_codes["54"] = new BranchNegative();
    instruction_codes["55"] = new BranchNegativeOrZero();
    instruction_codes["56"] = new BranchNotZero();
    instruction_codes["57"] = new BranchZero();
    instruction_codes["58"] = new BranchNotInfinite();
    instruction_codes["59"] = new BranchInfinite();

    instruction_codes["61"] = new ShiftLeft();
    instruction_codes["62"] = new ShiftRight();

    //instruction_codes["70"] = new Stop();
}

void CPU::addToMemory(Integer value) {
    loaded = true;
    if (instruction_amount < 100)
        memory_before[instruction_amount++] = value;
}
/*retorna:
    -1 se instrucao inexistente
    0 se finalizou
    1 se esta aguardando INPUT
    2 se eh pra escrever
    3 se a instrucao foi executada
*/

int CPU::execute(){
    /* Error handler basico para instrucoes inexistentes*/
    if (!instruction_codes[memory[PC].getFirstHalf()] 
        && memory[PC].getFirstHalf() != "31"
        && memory[PC].getFirstHalf() != "41"
        && memory[PC].getFirstHalf() != "70") {
        running = false;
        return -1;
    }

    /* 
     *   Pega o os dois primeiros digitos do codigo (que indica a intrucao)
     *   e busca no MAP `instruction_codes` a instrucao correspondente
     *   depois, executa a instrucao
    */
    if (memory[PC].getFirstHalf() == "70") { //encerrar
        PC++;
        running = false;   
        return 0;
    }
    if (memory[PC].getFirstHalf() == "31") //leitura
        return 1;
    if (memory[PC].getFirstHalf() == "41") //escrita
        return 2;
    instruction_codes[memory[PC].getFirstHalf()]->execute(this->PC, this->AC, this->memory, memory[PC]);
    return 3;
}

void CPU::updatePC() {
    PC++;
}

void CPU::initializeMemory() {
    PC = 0;
    AC = Integer();
    for (int i = 0; i < 100; i++) 
        memory[i] = memory_before[i];
}

void CPU::resetMemory() {
    loaded = false;
    instruction_amount = 0;
    delete [] memory;
    delete [] memory_before;
    memory = new Integer[100];
    memory_before = new Integer[100];
}

CPU::~CPU(){
    instruction_codes.clear();
    delete [] memory;
    delete [] memory_before;
}