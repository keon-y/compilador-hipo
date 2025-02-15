#include "Notification.hpp"

Notification::Notification(sf::RenderWindow &w) :
window {w}, isMovingDown {true}, isNotifying{false}
{
    this->text.setCharacterSize(30);
    this->text.setFillColor(sf::Color::White);
    
    box.setOutlineThickness(2);

    //centralizar no centro X e topo Y (a caixa)
    box.setSize({(float)window.getSize().x - 200, 100});
    box.setOrigin({box.getSize().x/2, box.getSize().y/2});

    
}

void Notification::setText(std::string text) {
    this->text.setString(text);
    this->text.setOrigin({this->text.getGlobalBounds().width/2, this->text.getGlobalBounds().height/2});
    
}

void Notification::setBgColor(char type) {
    switch (type){
        case 0: //verde
            box.setFillColor(sf::Color::Green);
            box.setOutlineColor(sf::Color::Yellow);
        break;
        case 1: //azul
            box.setFillColor(sf::Color::Blue);
            box.setOutlineColor(sf::Color::Yellow);
        break;
        case 2: //vermelho
            box.setFillColor(sf::Color::Red);
            box.setOutlineColor(sf::Color::Yellow);
        break;
    }

}

void Notification::setFont(sf::Font &font) {
    text.setFont(font);
}

void Notification::draw(){
    
    window.draw(box);
    window.draw(text);

}

void Notification::notify() {
    isNotifying = true;
    isMovingDown = true;
    box.setPosition({window.getSize().x/2.0f, box.getSize().y/-2.0f});
    this->text.setPosition({window.getSize().x/2.0f, -box.getSize().y/2.0f});
}
bool Notification::notifying() const { return isNotifying;}

void Notification::move(sf::Time &time) {
    if (isMovingDown) {
        box.move({0, 1});
        text.move({0, 1});
        isMovingDown = box.getPosition().y < box.getGlobalBounds().height/2;
        time = sf::Time::Zero;
    } else {

        if (time.asSeconds() >= 0.04f) {
            box.move({0, -1});
            text.move({0, -1});
        }
        if (box.getPosition().y < 0) isNotifying = false;
    }
}