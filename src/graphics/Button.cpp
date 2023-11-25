#include "Button.hpp"

Button::Button(sf::RenderWindow &w, std::string t, sf::Vector2f size, int fontSize, sf::Color bgColor, sf::Color textColor, sf::Color shadowColor) :
window {w}, active{true}, color{bgColor}
 {
    
    text.setString(t);
    text.setFillColor(textColor);
    text.setCharacterSize(fontSize);

    shadow.setString(t);
    shadow.setFillColor(sf::Color::Black);
    shadow.setCharacterSize(fontSize);

    button.setSize(size);
    button.setFillColor(bgColor);

    button_shadow.setSize(size);
    button_shadow.setFillColor(shadowColor);

}

void Button::setFont(sf::Font &font) {
    text.setFont(font);
    shadow.setFont(font);
}

void Button::setBgColor(sf::Color color, sf::Color shad) {
    button_shadow.setFillColor(shad);
    button.setFillColor(color);
}

void Button::setText(std::string text) {
    this->text.setString(text);
    shadow.setString(text);
}

void Button::setTextColor(sf::Color color) {
    text.setFillColor(color);
}

void Button::setPosition(sf::Vector2f pos) {
    button.setPosition(pos);
    button_shadow.setPosition({pos.x, pos.y + 10});

    //centralizar o texto no botao
    float xPos = (pos.x + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
    float yPos = (pos.y + button.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2) - 4;

    text.setPosition({xPos, yPos});
    shadow.setPosition({xPos, yPos + 2});

}

void Button::setActive(bool b){
    active = b;
    b ? button.setFillColor(color) : button.setFillColor(sf::Color(64,64,64));
}

void Button::draw(){
    if(active)
        window.draw(button_shadow);
    window.draw(button);
    window.draw(shadow); //A ordem importa
    window.draw(text);
}

bool Button::isMouseOver() {
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;
    float buttonX = button.getPosition().x;
    float buttonY = button.getPosition().y;
    float buttonEndX = buttonX + button.getLocalBounds().width;
    float buttonEndY = buttonY + button.getLocalBounds().height;

    return (mouseX < buttonEndX && mouseX > buttonX && mouseY < buttonEndY && mouseY > buttonY);
}