#include <SFML/Graphics.hpp>
#include "CPU.hpp"
#include "Button.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "SFML works!");
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
            }
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
                //mudar tamanho das coisas
            }
        }

        window.clear();
        execBtn.draw(window);
        loadBtn.draw(window);
        passoBtn.draw(window);
        window.display();
    }

    return 0;



    
}