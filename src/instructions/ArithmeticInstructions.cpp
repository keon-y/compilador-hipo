#include "ArithmeticInstructions.hpp"
#include <iostream>

void Add::execute(unsigned int& PC) {
    std::cout << "somou no acumulador" << std::endl;
    PC++;
}

void Subtract::execute(unsigned int& PC) {
    std::cout << "subtraiu no acumulador" << std::endl;
    PC++;
}

void Multiply::execute(unsigned int& PC) {
    std::cout << "multiplicou no acumulador" << std::endl;
    PC++;
}

void Divide::execute(unsigned int& PC) {
    std::cout << "dividiu no acumulador" << std::endl;
    PC++;
}

void Module::execute(unsigned int& PC) {
    std::cout << "modulo no acumulador" << std::endl;
    PC++;
}
