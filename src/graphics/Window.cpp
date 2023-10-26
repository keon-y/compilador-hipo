#include "Window.hpp"
#include <SFML/Graphics.hpp>

Janela::Janela(){
    window.create(sf::VideoMode(920, 600), "Compilador-HIPO", sf::Style::Titlebar | sf::Style::Close);
}

sf::Window* Janela::getWindow(){
    return &window;
}