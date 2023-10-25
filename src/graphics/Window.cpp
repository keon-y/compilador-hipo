#include "Window.hpp"
#include <SFML/Graphics.hpp>

class Janela{
    sf::Window window;
public:
    Janela(){
        window.create(sf::VideoMode(512, 512), "Compilador-HIPO", sf::Style::Titlebar | sf::Style::Close);
    }
    sf::Window* getWindow(){
        return &window;
    }
};