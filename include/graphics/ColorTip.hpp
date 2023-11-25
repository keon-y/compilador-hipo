#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class ColorTip {
    sf::RectangleShape color;
    sf::Text text;
    sf::RenderWindow &window;
    public:
        ColorTip(sf::RenderWindow &w, sf::Color c, sf::Vector2f size, std::string txt);
        void draw();
        void setFont(sf::Font &font);
        void setPosition(sf::Vector2f pos);
};