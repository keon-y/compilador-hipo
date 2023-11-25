#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Notification {

    sf::RectangleShape box;
    sf::Text text;
    sf::RenderWindow &window;
    bool isMovingDown;
    bool isNotifying;

    sf::Clock clock;
    sf::Time notification_effect_time;
    public:
        Notification(sf::RenderWindow &w);
        void draw();
        void setFont(sf::Font &font);
        void move();
        bool notifying() const;
        void notify(std::string text, int type);
};