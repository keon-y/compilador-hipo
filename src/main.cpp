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
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "SFML works!");
    
    StateMachine sm = StateMachine();
    sm.Initialize(StateMachine::build<MenuState>(sm, window, true));
    while (sm.isActive()) {
        sm.Run();
        sm.Update();
        sm.Render();
    }
    return 0;
    /*sf::View view = window.getDefaultView();



    float memInitialSize = 50;
    std::vector<MemoryBlock> memMap;



    for (int i = 0; i < 100; i++) {
        memMap.push_back(MemoryBlock(i, "+9999", sf::Vector2f(memInitialSize, memInitialSize), 12, 2, sf::Color::White, sf::Color::Black, sf::Color::White));
    }

    bool resized = false;
    sf::Vector2u windowSize;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {   
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                break;

                case sf::Event::MouseMoved:
                    execBtn.isMouseOver(window) ? execBtn.setBgColor(light_green) : execBtn.setBgColor(green);
                    loadBtn.isMouseOver(window) ? loadBtn.setBgColor(light_blue) : loadBtn.setBgColor(blue);
                    passoBtn.isMouseOver(window) ? passoBtn.setBgColor(light_blue) : passoBtn.setBgColor(blue);
                break;

                case sf::Event::Resized:
                    resized = true;
                    windowSize = window.getSize(); //atualizar o windowSize sempre que o usuario mudar o tamanho
                    sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                    window.setView(sf::View(visibleArea));
                break;

                
            }
        }
        window.clear();



        //execBtn.draw(window);
        //loadBtn.draw(window);
        //passoBtn.draw(window);
        
        //desenhar os blocos de memoria
        float x0_pos = (windowSize.x - ((10 * memMap[0].getSize() + MEMBLOCK_X_OFFSET) - MEMBLOCK_X_OFFSET)) / 2; //descobrir o x0 ideal para centralizar os 10 elementos
        for (int i = 0; i < memMap.size(); i++) {
            
            int current_inline = (i % MAX_MEMBLOCK_PER_LINE); //quantos blocos tem na linha que esta sendo desenhada
            int yLevel = floor(i / MAX_MEMBLOCK_PER_LINE); //Qual a altura da linha desenhada (comeca em 0)

            float xPos = x0_pos + memMap[i].getSize() * current_inline + MEMBLOCK_X_OFFSET * current_inline; 
            float yPos = 200 + memMap[i].getSize() * yLevel + yLevel * MEMBLOCK_Y_OFFSET;
            
            if (resized) {
                memMap[i].setFont(font);
                memMap[i].setPosition({xPos, yPos});
            }
            memMap[i].draw(window);
        }
        resized = false;
        window.display();
    }*/

    //return 0;



    
}