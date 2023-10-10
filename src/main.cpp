#include <SFML/Graphics.hpp>
#include "CPU.hpp"
#include "ArithmeticInstructions.hpp"
#include <iostream>

int main()
{
    CPU teste = CPU();
    teste.addToMemory(Integer("+3150"));
    teste.addToMemory(Integer("+4150"));
    
    teste.executeProgram(); 


    return 0;
}