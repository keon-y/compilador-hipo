#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {

    sf::Text text, shadow;
    sf::RectangleShape button, button_shadow;
    sf::RenderWindow &window;

    public:
        Button(sf::RenderWindow &w, 
            std::string t, 
            sf::Vector2f size, 
            int fontSize, 
            sf::Color bgColor, 
            sf::Color textColor,
            sf::Color shadow_color);
        void setFont(sf::Font &font);
        void setBgColor(sf::Color color);
        void setTextColor(sf::Color color);
        void setPosition(sf::Vector2f pos);
        void draw();
        bool isMouseOver();
};