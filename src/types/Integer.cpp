#include "Integer.hpp"

#define INTEGER_SIZE 4

/*
    Tipo INTEIRO, formato SINAL e INTEGER_SIZE NUMEROS DECIMAIS em sequencia
*/

/* Construtor padrao (inicia em zero) */
Integer::Integer() {
    this->num = '+';
    while (num.length() < INTEGER_SIZE + 1)
        num += '0'; 
}


/* Construtor que usa uma string como argumento*/
Integer::Integer(std::string num){

    /* Coloca o sinal no INTEIRO caso nao tenha */
    if (num[0] != '+' && num[0] != '-')
        num = '+' + num;

    /* Arruma os decimais para que tenham o numero fixo de casas (INTEGER_SIZE) */
    if (num.length() < INTEGER_SIZE + 1){

        /* Armazena o sinal e apaga ele da string */
        char signal = num[0];
        num.erase(0, 1);

        /* Adiciona zeros no MSB ate dar o tamanho certo */
        while (num.length() < INTEGER_SIZE)
            num = '0' + num; 

        num = signal + num;
    }
    
    this->num = num;
}

Integer::Integer(int num) {
    std::string new_num = std::to_string(num);

    /* Coloca o sinal no INTEIRO caso nao tenha */
    if (new_num[0] != '+' && new_num[0] != '-')
        new_num = '+' + new_num;

    /* Arruma os decimais para que tenham o numero fixo de casas (INTEGER_SIZE) */
    if (new_num.length() < INTEGER_SIZE + 1){

        /* Armazena o sinal e apaga ele da string */
        char signal = new_num[0];
        new_num.erase(0, 1);

        /* Adiciona zeros no MSB ate dar o tamanho certo */
        while (new_num.length() < INTEGER_SIZE)
            new_num = '0' + new_num; 

        new_num = signal + new_num;
    }
    
    this->num = new_num;
    
}

/* Retorna a PRIMEIRA METADE do tipo Integer como uma string */
std::string Integer::getFirstHalf() const {
    return num.substr(1, INTEGER_SIZE / 2);
}

/* Retorna a SEGUNDA METADE do tipo Integer como uma string */
std::string Integer::getSecondHalf() const {
    return num.substr(1 + INTEGER_SIZE / 2, INTEGER_SIZE / 2);
}

/* Retorna a SEGUNDA METADE do tipo Integer como um unsigned int */
unsigned int Integer::getNumericHalf() const {
    return std::stoi(num.substr(1 + INTEGER_SIZE / 2, INTEGER_SIZE / 2));
}

/* Converte do tipo Integer para um tipo int (typecast)*/
Integer::operator int() {
    return num[0] == '+' ? std::stoi(num.substr(1, INTEGER_SIZE / 2)) : std::stoi(num.substr(1, INTEGER_SIZE / 2)) * -1;
}

Integer Integer::operator+= (Integer &other) {

    if (this->isOverflown() || other.isOverflown())
        return Integer("-0");

    int result = stoi(num) + (int)other;
    std::string new_str = std::to_string(result);
    size_t size = new_str.size();

    if ((size > 4 && new_str[0] != '-') && (new_str[0] == '-' && size > 5)) {
        //OVERFLOW

    }
        
}