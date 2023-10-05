#include "ArithmeticInstructions.hpp"
#include <iostream>

void Add::execute(unsigned int& PC, Integer num) {
    std::cout << "somou " << num.getNumericHalf() <<  " no acumulador" << std::endl;
    PC++;
}

void Subtract::execute(unsigned int& PC, Integer num) {
    std::cout << "subtraiu " << num.getNumericHalf() <<  " no acumulador" << std::endl;
    PC++;
}

void Multiply::execute(unsigned int& PC, Integer num) {
    std::cout << "multiplicou " << num.getNumericHalf() <<  " no acumulador" << std::endl;
    PC++;
}

void Divide::execute(unsigned int& PC, Integer num) {
    std::cout << "dividiu " << num.getNumericHalf() <<  " no acumulador" << std::endl;
    PC++;
}

void Module::execute(unsigned int& PC, Integer num) {
    std::cout << "modulo " << num.getNumericHalf() <<  " no acumulador" << std::endl;
    PC++;
}
