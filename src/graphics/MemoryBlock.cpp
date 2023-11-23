#include "MemoryBlock.hpp"

MemoryBlock::MemoryBlock(sf::RenderWindow &w, std::string title, std::string storedValue, sf::Vector2f boxSize, int fontSize, int outlineThickness, sf::Color fontColor, sf::Color bgColor, sf::Color outlineColor) :
window {w}
{
    
    address.setString(title);
    address.setFillColor(fontColor);
    address.setCharacterSize(fontSize);

    value.setString(storedValue);
    value.setFillColor(fontColor);
    value.setCharacterSize(fontSize + 3);

    box.setFillColor(bgColor);
    box.setOutlineThickness(outlineThickness);
    box.setOutlineColor(outlineColor);
    box.setSize(boxSize);
}


void MemoryBlock::setSize(sf::Vector2f size) {
    box.setSize(size);
    //mudar ou nao o tamanh do outline 
}

void MemoryBlock::setPosition(sf::Vector2f pos) {
    box.setPosition(pos);

    //o indice fica centralizado na parte superior da caixa

    sf::FloatRect textRect = value.getLocalBounds();
    value.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);

    float xPos = (pos.x + box.getGlobalBounds().width / 2) - (address.getGlobalBounds().width / 2);
    float yPos = pos.y + address.getGlobalBounds().height - 8;
    address.setPosition({xPos, yPos});

    value.setPosition({pos.x + box.getGlobalBounds().width / 2 - 2, pos.y + box.getGlobalBounds().height / 2});

}

void MemoryBlock::setText(std::string val) {
    value.setString(val);
}

void MemoryBlock::setFont(sf::Font &font) {
    value.setFont(font);
    address.setFont(font);
}

void MemoryBlock::setFontSize(unsigned int size) {
    address.setCharacterSize(size);
    value.setCharacterSize(size + 3);
} 

void MemoryBlock::draw() {
    window.draw(box);
    window.draw(address);
    window.draw(value);
}

float MemoryBlock::getSize() const {
    return box.getGlobalBounds().width;
}

void MemoryBlock::setBorderColor(sf::Color color) {
    box.setOutlineColor(color);
}