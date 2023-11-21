#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class MemoryBlock {
    sf::Text address;
    sf::Text value;
    sf::RectangleShape box;
    sf::RenderWindow &window;
    public:
        /*
            1. indice do bloco de memoria
            2. valor armazenado no bloco
            3. posicao do bloco (x, y)
            4. tamanho da fonte (px)
            5. tamanho do outline (px)
            6. cor da fonte
        */
        MemoryBlock(sf::RenderWindow &, int, std::string, sf::Vector2f, int, int , sf::Color, sf::Color, sf::Color);
        void setSize(sf::Vector2f);
        void setPosition(sf::Vector2f);
        void setText(std::string);
        void setFont(sf::Font &);
        void setFontSize(unsigned int);
        void draw();
        float getSize() const;
};