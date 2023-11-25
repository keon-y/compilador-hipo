#include "ShiftInstructions.hpp"


void ShiftLeft::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    std::string t = AC.toString();
    t.erase(1, 1);
    AC = Integer(t + "0");
}

void ShiftRight::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    std::string t = AC.toString();
    char signal = t[0];
    t.erase(0,1);
    t.erase(3,1);
    t = '0' + t;
    t = signal + t;
    AC = Integer(t);
}