#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {

    sf::Vector2f size;
    sf::Text text, shadow;
    sf::RectangleShape button;
    sf::RenderWindow &window;

    public:
        Button(sf::RenderWindow &w, std::string t, sf::Vector2f size, int fontSize, sf::Color bgColor, sf::Color textColor);
        void setFont(sf::Font &font);
        void setBgColor(sf::Color color);
        void setTextColor(sf::Color color);
        void setPosition(sf::Vector2f pos);
        void draw();
        bool isMouseOver();
};