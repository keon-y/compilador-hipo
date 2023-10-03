#pragma once
#include <string>

//o tipo INTEIRO eh composto por um sinal + ou - seguido de 4 digitos decimais
class Integer {
    std::string num;

    public:
        Integer();
        Integer(std::string num);
};