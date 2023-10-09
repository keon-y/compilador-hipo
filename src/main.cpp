#include <SFML/Graphics.hpp>
#include "CPU.hpp"
#include "ArithmeticInstructions.hpp"
#include <iostream>

int main()
{
    /*CPU teste = CPU();
    teste.addToMemory(Integer("+2150"));
    teste.addToMemory(Integer("+2250"));
    teste.addToMemory(Integer("+2350"));
    teste.addToMemory(Integer("+2450"));
    teste.addToMemory(Integer("+2550"));
    
    std::cout << "Setando AC para 10" << std::endl;
    teste.setAC(Integer(10));

    std::cout << "Setando memoria[50] para 2" << std::endl;
    *teste.getAddress(50) = Integer(2);
    
    teste.executeProgram(); */

    Integer a = Integer("5342");
    std::cout << "Valor inicial = " << (int)a << std::endl; 
    Integer b = Integer(1);
    a += b;
    std::cout << "Somado com 1 = " << (int)a << std::endl; 

    Integer c = Integer("4657");
    a+=c;
    std::cout << "Somado com 4657 (OVERFLOW) = " << (int)a << std::endl; 

    return 0;
}