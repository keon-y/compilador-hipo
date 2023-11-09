#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class MemoryBlock {
    sf::Text address;
    sf::Text value;
    sf::RectangleShape box;

    public:
        /*
            1. indice do bloco de memoria
            2. valor armazenado no bloco
            3. posicao do bloco (x, y)
            4. tamanho da fonte (px)
            5. tamanho do outline (px)
            6. cor da fonte
        */
        MemoryBlock(int index, std::string storedValue, sf::Vector2f boxSize, int fontSize, int outlineThickness, sf::Color fontColor, sf::Color bgColor, sf::Color outlineColor);
        void setSize(sf::Vector2f);
        void setPosition(sf::Vector2f);
        void setText(std::string);
        void setFont(sf::Font &);
        void setFontSize(unsigned int);
        void draw(sf::RenderWindow &);
        float getSize() const;
};