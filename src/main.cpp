#include <SFML/Graphics.hpp>
#include "CPU.hpp"
#include "Button.hpp"
#include "MemoryBlock.hpp"
#include <iostream>
#include <cmath>

#define MAX_MEMBLOCK_PER_LINE 10
#define MEMBLOCK_X_OFFSET 5
#define MEMBLOCK_Y_OFFSET 20
#define MEMBLOCK_PADDING_SIDE 30
#define MEMBLOCK_PADDING_TOP 100

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "SFML works!");
    sf::View view = window.getDefaultView();

    sf::Font font;
    font.loadFromFile("font.ttf");

    //PALETA
    sf::Color green = sf::Color(162, 197, 121);
    sf::Color light_green = sf::Color(210, 222, 50);

    sf::Color blue = sf::Color(97, 163, 186);
    sf::Color light_blue = sf::Color(125, 191, 201);

    Button execBtn("Executar", {220, 80}, 30, green, sf::Color::White);
    execBtn.setFont(font);
    execBtn.setPosition({300, 200});

    Button loadBtn("Carregar", {220, 80}, 30, blue, sf::Color::White);
    loadBtn.setFont(font);
    loadBtn.setPosition({300, 370});

    Button passoBtn("Passo a Passo", {220, 80}, 30, blue, sf::Color::White);
    passoBtn.setFont(font);
    passoBtn.setPosition({300, 540});


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
                    window.getSize().x < 800 ? view.zoom(1.2) : view.zoom(1);
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
    }

    return 0;



    
}