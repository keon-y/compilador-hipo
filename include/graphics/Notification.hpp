#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Notification {

    sf::RectangleShape box;
    sf::Text text;
    sf::RenderWindow &window;
    bool isMovingDown;
    bool isNotifying;
    public:
        Notification(sf::RenderWindow &w);
        void draw();
        void setFont(sf::Font &font);
        void move(sf::Time &time);
        bool notifying() const;
        void notify();
        void setText(std::string text);
        void setBgColor(char type);
};