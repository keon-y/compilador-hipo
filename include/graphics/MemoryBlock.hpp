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
            1. RenderWindow que vai ser desenhado
            2. Titulo do bloco
            3. Conteudo do bloco
            4. Tamanho do bloco (width, height)
            5. Tamanho da fonte
            6. Tamanho da borda
            7. Cor da fonte
            8. Cor do fundo
            9. Cor da borda
        */
        MemoryBlock(sf::RenderWindow &, std::string, std::string, sf::Vector2f, int, int , sf::Color, sf::Color, sf::Color);
        void setSize(sf::Vector2f);
        void setPosition(sf::Vector2f);
        void setText(std::string);
        void setFont(sf::Font &);
        void setFontSize(unsigned int);
        void draw();
        float getSize() const;
        void setBorderColor(sf::Color color);
};