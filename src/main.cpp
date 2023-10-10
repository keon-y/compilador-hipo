#include <SFML/Graphics.hpp>
#include "CPU.hpp"
#include "ArithmeticInstructions.hpp"
#include <iostream>

int main()
{
    CPU teste = CPU();
    //le um valor e coloca no endereco 50 (0)
    teste.addToMemory(Integer("+3150"));

    //printa o endereco 50 (1)
    teste.addToMemory(Integer("+4150"));

    //pula pro final (2)
    teste.addToMemory(Integer("+5109"));

    //coloca o valor do end 50 no ac (3)
    teste.addToMemory(Integer("+1150"));

    //le um valor e coloca no endereco 50 (4)
    teste.addToMemory(Integer("+3150"));

    //printa o endereco 50 (5)
    teste.addToMemory(Integer("+4150"));

    //soma o conteudo do ac com o do endereco 50 (6)
    teste.addToMemory(Integer("+2150"));

    //coloca o valor do ac no ed 50 (7)
    teste.addToMemory(Integer("+1250"));

    //printa o endereco 50 (8)
    teste.addToMemory(Integer("+4150"));
    
    //finaliza (9)
    teste.addToMemory(Integer("+7000"));

    teste.executeProgram(); 


    return 0;
}