#include <SFML/Graphics.hpp>
#include "CPU.hpp"
#include "ArithmeticInstructions.hpp"
#include <iostream>

int main()
{
    CPU teste = CPU();
    //le um valor e coloca no endereco 50
    teste.addToMemory(Integer("+3150"));

    //printa o endereco 50
    teste.addToMemory(Integer("+4150"));

    //coloca o valor do end 50 no ac
    teste.addToMemory(Integer("+1150"));

    //le um valor e coloca no endereco 50
    teste.addToMemory(Integer("+3150"));

    //printa o endereco 50
    teste.addToMemory(Integer("+4150"));

    //soma o conteudo do ac com o do endereco 50
    teste.addToMemory(Integer("+2150"));

    //coloca o valor do ac no ed 50
    teste.addToMemory(Integer("+1250"));

    //printa o endereco 50
    teste.addToMemory(Integer("+4150"));
    
    teste.executeProgram(); 


    return 0;
}