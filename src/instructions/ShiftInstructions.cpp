#include "ShiftInstructions.hpp"


void ShiftLeft::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    AC = Integer(AC.toString().erase(1) + "0");
}

void ShiftRight::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    std::string t = AC.toString();
    char signal = t[0];
    t.erase(0);
    AC = Integer(signal + "0" + t.erase(3));
}