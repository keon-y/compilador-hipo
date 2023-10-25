#include <SFML/Graphics.hpp>
#include "CPU.hpp"
#include "ArithmeticInstructions.hpp"
#include "Window.hpp"
#include <iostream>

int main()
{
    CPU teste = CPU();
    Janela mainWindow;

    while(mainWindow.getWindow()->isOpen()){
        sf::Event evnt;

        while(mainWindow.getWindow()->pollEvent(evnt))
            if(evnt.type == sf::Event::Closed)
                mainWindow.getWindow()->close();
    }

    teste.addToMemory(Integer("+1130")); //0
    teste.addToMemory(Integer("+1240")); //1
    teste.addToMemory(Integer("+3150")); //2
    teste.addToMemory(Integer("+4150")); //3
    teste.addToMemory(Integer("+1150")); //4
    teste.addToMemory(Integer("+5410")); //5
    teste.addToMemory(Integer("+1140")); //6
    teste.addToMemory(Integer("+2150")); //7
    teste.addToMemory(Integer("+1240")); //8
    teste.addToMemory(Integer("+5102")); //9
    teste.addToMemory(Integer("+4140")); //10
    teste.addToMemory(Integer("+7000")); //11


    teste.executeProgram(); 


    return 0;
}