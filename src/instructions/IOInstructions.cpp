#include "IOInstructions.hpp"

void Read::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    int r;
    std::cin >> r;
    *(memory + num.getNumericHalf()) = Integer(r);
}

void Print::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    std::cout << (*(memory + num.getNumericHalf())).toString() << std::endl;
}