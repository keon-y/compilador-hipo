#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Textbox {

    sf::Text display_text;
    std::string text;
    sf::RenderWindow &window;
    sf::RectangleShape box;
    bool selected;

    public:
        Textbox(sf::RenderWindow &w, 
            sf::Vector2f size, 
            sf::Color border, 
            sf::Color textColor, 
            int textSize,
            sf::Color bgColor);
        

        void setPosition(sf::Vector2f pos);
        void setFont(sf::Font &font);
        void setSelected(bool sel);
        void addChar(int c);
        void pop();
        void update(bool);
        void draw();

        bool isSelected() const;
        bool isMouseOver() const;
        std::string getText() const;
};