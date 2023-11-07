#include "Button.hpp"

Button::Button(std::string t, sf::Vector2f size, int fontSize, sf::Color bgColor, sf::Color textColor) {
    text.setString(t);
    text.setFillColor(textColor);
    text.setCharacterSize(fontSize);

    shadow.setString(t);
    shadow.setFillColor(sf::Color::Black);
    shadow.setCharacterSize(fontSize);

    button.setSize(size);
    this->size = size;
    button.setFillColor(bgColor);
}

void Button::setFont(sf::Font &font) {
    text.setFont(font);
    shadow.setFont(font);
}

void Button::setBgColor(sf::Color color) {
    button.setFillColor(color);
}

void Button::setTextColor(sf::Color color) {
    text.setFillColor(color);
}

void Button::setPosition(sf::Vector2f pos) {
    button.setPosition(pos);

    //centralizar o texto no botao
    float xPos = (pos.x + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
    float yPos = (pos.y + button.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2) - 4;

    text.setPosition({xPos, yPos});
    shadow.setPosition({xPos, yPos + 2});

}

void Button::draw(sf::RenderWindow &window){
    window.draw(button);
    window.draw(shadow); //A ordem importa
    window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow &window) {
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;
    float buttonX = button.getPosition().x;
    float buttonY = button.getPosition().y;
    float buttonEndX = buttonX + button.getLocalBounds().width;
    float buttonEndY = buttonY + button.getLocalBounds().height;

    return (mouseX < buttonEndX && mouseX > buttonX && mouseY < buttonEndY && mouseY > buttonY);
}