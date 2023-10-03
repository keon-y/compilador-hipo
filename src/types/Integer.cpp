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
