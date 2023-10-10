#pragma once
#include <string>
#include <math.h>

//o tipo INTEIRO eh composto por um sinal + ou - seguido de 4 digitos decimais
class Integer {
    std::string num;

    public:
        /* Construtor Padrao (inicia o inteiro em ZERO) */
        Integer();

        /* Construtor que usa uma string para atribuir um valor*/
        Integer(std::string num);
        Integer(int num);

        /* TODO: operator =*/

        std::string getNumber() const;
        std::string getFirstHalf() const;
        std::string getSecondHalf() const;
        unsigned int getNumericHalf() const;
        operator int();
        Integer& operator+= (Integer& other);
        bool isOverflown() const;
        inline std::string toString() const { return num; }
};