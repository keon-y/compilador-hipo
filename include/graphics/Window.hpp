#pragma once
#include <SFML/Graphics.hpp>

class Janela{
    sf::Window window;
public:
    Janela();
    sf::Window* getWindow();
};