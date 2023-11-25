#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Textbox {

    sf::Text display_text;
    std::string text;
    sf::RenderWindow &window;
    sf::RectangleShape box;
    bool selected;

    //Animacao
    sf::Clock clock;
    sf::Time text_effect_time;
    bool show_cursor;

    public:
        /*
            1. RenderWindow
            2. tamanho {width, height} da caixa
            3. Cor da borda da caixa
            4. Cor do texto
            5. tamanho do texto
            6. Cor de fundo da caixa
        */
        Textbox(sf::RenderWindow &w, 
            sf::Vector2f size, 
            sf::Color border, 
            sf::Color textColor, 
            int textSize,
            sf::Color bgColor);
        

        void setPosition(sf::Vector2f pos);
        void setFont(sf::Font &font);
        void setSelected(bool sel);
        void setText(std::string text);
        void setBorderColor(sf::Color color);
        void addChar(int c);
        void pop();
        void update();
        void draw();

        bool isSelected() const;
        bool isMouseOver() const;
        std::string getText() const;
};