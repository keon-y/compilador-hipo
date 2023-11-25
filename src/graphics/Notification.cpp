#include "Notification.hpp"

#include "Colors.hpp"

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


void Notification::setFont(sf::Font &font) {
    text.setFont(font);
}

void Notification::draw(){
    
    window.draw(box);
    window.draw(text);

}

void Notification::notify(std::string text, int type) {

    switch (type){
        case 0: //verde
            box.setFillColor(light_green);
            box.setOutlineColor(dark_green);
        break;
        case 1: //azul
            box.setFillColor(light_blue);
            box.setOutlineColor(dark_blue);
        break;
        case 2: //vermelho
            box.setFillColor(light_red);
            box.setOutlineColor(dark_red);
        break;
    }

    this->text.setString(text);
    this->text.setOrigin({this->text.getGlobalBounds().width/2, this->text.getGlobalBounds().height/2});

    isNotifying = true;
    isMovingDown = true;
    box.setPosition({window.getSize().x/2.0f, box.getSize().y/-2.0f});
    this->text.setPosition({window.getSize().x/2.0f, -box.getSize().y/2.0f});

    
}
bool Notification::notifying() const { return isNotifying;}

void Notification::move() {
    notification_effect_time += clock.restart();
    if (notification_effect_time >= sf::seconds(0.005f)) {
        if (isMovingDown) {
            box.move({0, 1});
            text.move({0, 1});
            isMovingDown = box.getPosition().y < box.getGlobalBounds().height/2;
            notification_effect_time = sf::Time::Zero;
        } else {
            if (notification_effect_time.asSeconds() >= 2.5f) {
                box.move({0, -1});
                text.move({0, -1});
            }
            if (box.getPosition().y < box.getGlobalBounds().height / -2.0f) isNotifying = false;
        }
    }
}