#include <SFML/Graphics.hpp>
#include "CPU.hpp"
#include "Button.hpp"
#include "MemoryBlock.hpp"
#include "StateMachine.hpp"
#include "States.hpp"
#include <iostream>
#include <cmath>



int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!", sf::Style::Close); 
    CPU cpu = CPU();
    StateMachine sm = StateMachine(cpu);
    sm.Initialize(StateMachine::build<MenuState>(sm, window, true));
    while (sm.isActive()) {
        sm.Run();
        sm.Update();
        sm.Render();
    }
    return 0;


    
}