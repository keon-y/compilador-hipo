#include "ArithmeticInstructions.hpp"


void Add::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;

    /* Qualquer operacao sobre um numero com overflow resulta em um numero com overflow*/
    if ( (*(memory + num.getNumericHalf())).isOverflown() || AC.isOverflown())
        AC = Integer("-0");
    else AC = (int) *(memory + num.getNumericHalf()) + (int) AC;
}

void Subtract::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    
    if ( (*(memory + num.getNumericHalf())).isOverflown() || AC.isOverflown())
        AC = Integer("-0");
    else AC = (int)AC - (int)(*(memory + num.getNumericHalf()));
}

void Multiply::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    
    if ( (*(memory + num.getNumericHalf())).isOverflown() || AC.isOverflown())
        AC = Integer("-0");
    else AC = (int) *(memory + num.getNumericHalf()) * (int) AC;
}

void Divide::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) {
    PC++;
    
    if ( (*(memory + num.getNumericHalf())).isOverflown() || AC.isOverflown())
        AC = Integer("-0");
    else AC = (int)AC / (int)(*(memory + num.getNumericHalf()));
}

void Module::execute(unsigned int& PC, Integer &AC, Integer* memory, Integer num) { 
    PC++;
    
    if ( (*(memory + num.getNumericHalf())).isOverflown() || AC.isOverflown())
        AC = Integer("-0");
    else AC = (int)AC % (int)(*(memory + num.getNumericHalf()));
}
