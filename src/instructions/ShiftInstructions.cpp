#include "ShiftInstructions.hpp"

void ShiftLeft::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    AC = Integer(AC.toString().erase(1) + "0");
}

void ShiftRight::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    AC = AC = Integer("0" + AC.toString().erase(4));
}