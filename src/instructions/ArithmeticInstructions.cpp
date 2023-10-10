#include "ArithmeticInstructions.hpp"


void Add::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    //std::cout << "somou " << AC << " + " << *(memory + num.getNumericHalf()) <<  " no acumulador" << std::endl;
    PC++;
    AC += *(memory + num.getNumericHalf());
}

void Subtract::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    //std::cout << "subtraiu " << num.getNumericHalf() <<  " no acumulador" << std::endl;
}

void Multiply::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    //std::cout << "multiplicou " << num.getNumericHalf() <<  " no acumulador" << std::endl;
}

void Divide::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    //std::cout << "dividiu " << num.getNumericHalf() <<  " no acumulador" << std::endl;
}

void Module::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    //std::cout << "modulo " << num.getNumericHalf() <<  " no acumulador" << std::endl;
}
