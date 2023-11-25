#include "ColorTip.hpp"
#include "Colors.hpp"

ColorTip::ColorTip(sf::RenderWindow &w, sf::Color c, sf::Vector2f size, std::string txt) :
window{w}
{
    color.setSize(size);
    color.setFillColor(c);
    color.setOutlineThickness(1);
    color.setOutlineColor(white);
    color.setOrigin({color.getGlobalBounds().width/2, color.getGlobalBounds().height/2});

    text.setString(txt);
    text.setCharacterSize(13);
    text.setFillColor(white);
}

void ColorTip::setFont(sf::Font &font) {
    text.setFont(font);
    text.setOrigin({0, text.getGlobalBounds().height});
}

void ColorTip::setPosition(sf::Vector2f pos) {
    color.setPosition(pos);
    text.setPosition({pos.x + 15, pos.y});
}

void ColorTip::draw() {
    window.draw(color);
    window.draw(text);
}