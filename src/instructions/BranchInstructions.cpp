#include "BranchInstructions.hpp"

void NoOperation::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
}

void Branch::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC = num.getNumericHalf();
}