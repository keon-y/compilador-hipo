#include "Instruction.hpp"

Instruction::Instruction(std::string code) {
    this->code = code;
}

Integer Instruction::getCode() {
    return code;
}