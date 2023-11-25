#include "Textbox.hpp"

Textbox::Textbox(sf::RenderWindow &w, sf::Vector2f size, sf::Color border, sf::Color textColor, int textSize, sf::Color bgColor)
: window {w} { 
    box.setSize(size);
    box.setFillColor(bgColor);
    box.setOutlineThickness(2);
    box.setOutlineColor(border);
    box.setOrigin({size.x/2, size.y/2});
    display_text.setOrigin({size.x/2, size.y/2});
    display_text.setFillColor(textColor);
    display_text.setCharacterSize(textSize);

}

void Textbox::addChar(int c) {
    text += static_cast<char>(c);
    text_effect_time = sf::Time::Zero; //nao mostrar o _ quando ta digitando
    show_cursor = false;
}

void Textbox::pop() {
    if (!text.empty()) 
        text.pop_back();
    
}

void Textbox::setFont(sf::Font &font) {
    display_text.setFont(font);
}

void Textbox::setPosition(sf::Vector2f pos) {
    box.setPosition(pos);

    float yPos = (pos.y + box.getGlobalBounds().height / 2) - (display_text.getGlobalBounds().height / 2) - 4;

    display_text.setPosition({pos.x + 4, yPos - 4});
}

bool Textbox::isSelected() const {
    return selected;
}

bool Textbox::isMouseOver() const {
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    //precisa ajustar por causa do setorigin
    float boxX = box.getPosition().x - box.getSize().x/2;
    float boxY = box.getPosition().y - box.getSize().y/2;
    float boxEndX = boxX + box.getLocalBounds().width;
    float boxEndY = boxY + box.getLocalBounds().height;

    return (mouseX < boxEndX && mouseX > boxX && mouseY < boxEndY && mouseY > boxY);
}

void Textbox::setSelected(bool sel) {
    selected = sel;
}

void Textbox::draw() {
    window.draw(box);
    window.draw(display_text);
}

void Textbox::update() { //ficar piscando o _ quando esta selecionado porem nao digitando
    text_effect_time += clock.restart();
    if (text_effect_time >= sf::seconds(0.5f) ) {
            show_cursor = !show_cursor;
            text_effect_time = sf::Time::Zero;
    }
    show_cursor && selected ? display_text.setString(text + "_") : display_text.setString(text);
}

std::string Textbox::getText() const {
    return text;
}

void Textbox::setText(std::string text) {
    display_text.setString(text);
    this->text = text;
}

void Textbox::setBorderColor(sf::Color color) {
    box.setOutlineColor(color);
}