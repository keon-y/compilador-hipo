#include "CopyInstructions.hpp"

void CopyEA::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    AC = *(memory + num.getNumericHalf());
}

void CopyAE::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    *(memory + num.getNumericHalf()) = AC;
}