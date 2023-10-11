#include "BranchInstructions.hpp"

void NoOperation::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
}

void Branch::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC = num.getNumericHalf();
}

void BranchPositive::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    if ((int) AC > 0 && !AC.isOverflown())
        PC = num.getNumericHalf();
}

void BranchPositiveOrZero::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    if ((int) AC >= 0 && !AC.isOverflown())
        PC = num.getNumericHalf();
}

void BranchNegative::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    if ((int) AC < 0 && !AC.isOverflown())
        PC = num.getNumericHalf();
}

void BranchNegativeOrZero::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    if ((int) AC <= 0 && !AC.isOverflown())
        PC = num.getNumericHalf();
}

void BranchZero::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    if ((int) AC == 0 && !AC.isOverflown())
        PC = num.getNumericHalf();
}

void BranchNotZero::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    if ((int) AC != 0 && !AC.isOverflown())
        PC = num.getNumericHalf();
}

void BranchInfinite::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    if (AC.isOverflown())
        PC = num.getNumericHalf();
}

void BranchNotInfinite::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    if (!AC.isOverflown())
        PC = num.getNumericHalf();
}