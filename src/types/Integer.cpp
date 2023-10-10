#include "Integer.hpp"

#define INTEGER_SIZE 4
#define INTEGER_OVERFLOW_VALUE 10000
#define OVERFLOW "-0000"

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

    //OVERFLOW
    if (num.size() > INTEGER_SIZE + 1)  {
        this->num = OVERFLOW;
        return;
    }

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
    //caso overflow
    if ((new_num.size() > INTEGER_SIZE && new_num[0] != '-') || (new_num[0] == '-' && new_num.size() > INTEGER_SIZE + 1)) {
        this->num = OVERFLOW;
        return;
    }

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

/* Retorna se um tipo Integer deu overflow */
bool Integer::isOverflown() const {
    return (num == OVERFLOW);
}


/* Converte do tipo Integer para um tipo int (typecast)*/
Integer::operator int() {
    if (this->isOverflown())
       return INTEGER_OVERFLOW_VALUE;
    return num[0] == '+' ? std::stoi(num.substr(1, INTEGER_SIZE)) : std::stoi(num.substr(1, INTEGER_SIZE)) * -1;
}

Integer& Integer::operator+= (Integer &other) {

    //uma soma com qualquer overflow resulta em overflow
    if (this->isOverflown() || other.isOverflown()) {
        this->num = OVERFLOW;
        return *this;
    }

    int result = stoi(num) + (int)other;
    std::string new_str = result < 0 ? "-" + std::to_string(result) : "+" + std::to_string(result);

    //checa se o novo numero deu overflow
    if (new_str.size() > INTEGER_SIZE + 1) 
        this->num = OVERFLOW;
    else this->num = new_str;
    
    return *this;
        
}