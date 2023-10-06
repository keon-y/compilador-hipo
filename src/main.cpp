#include <SFML/Graphics.hpp>
#include "CPU.hpp"
#include "ArithmeticInstructions.hpp"
#include <iostream>

int main()
{
    CPU teste = CPU();
    teste.addToMemory(Integer("+2150"));
    teste.addToMemory(Integer("+2250"));
    teste.addToMemory(Integer("+2350"));
    teste.addToMemory(Integer("+2450"));
    teste.addToMemory(Integer("+2550"));
    
    std::cout << "Setando AC para 10" << std::endl;
    teste.setAC(Integer(10));

    std::cout << "Setando memoria[50] para 2" << std::endl;
    *teste.getAddress(50) = Integer(2);
    
    teste.executeProgram();

    return 0;
}