#pragma once

#include "State.hpp"
#include "StateMachine.hpp"
#include "Button.hpp"
#include "MemoryBlock.hpp"
#include "Textbox.hpp"
#include "Notification.hpp"
#include "ColorTip.hpp"


class MenuState : public State {
    sf::Text txt;
    sf::Font font;
    Button executeBtn;
    Button loadBtn;
    Button returnBtn;

    public:
        MenuState(StateMachine &sm, sf::RenderWindow &w, const bool isRepl);

        void update() override;
        void render() override;

};

class ExecutingState : public State {

    sf::Font font;
    std::vector<MemoryBlock> mem_map;
    MemoryBlock pc;
    MemoryBlock ac;
    Button returnBtn;

    bool isWaitingInput;
    std::string input;
    Textbox ioBox;
    Button submitBtn;

    sf::Text consoleTxt;

    Notification notif;

    sf::Time execute_time; //controlar o tempo de cada execução
    sf::Time notification_effect_time;

    /*
    CORES: azul     = valor sendo lido
           vermelho = valor sendo sobrescrevido
           verde    = executando
           roxo     = apontado pelo pc
        */
    ColorTip blueTip;
    ColorTip redTip;
    ColorTip greenTip;
    ColorTip purpleTip;

    public:
        ExecutingState(StateMachine &sm, sf::RenderWindow &w, const bool isRepl);

        void update() override;
        void render() override;
};

class LoadState : public State {
    //efeito para aparecer e sumir o _ na digitacao
  
    sf::Time text_effect_time;
    bool show_cursor = true;

    //GUI
    sf::Font font;
    Button returnBtn;
    Textbox textbox;
    sf::Text txt;
    Button submitBtn;

    Notification notif;
    sf::Time notification_effect_time;

    public:
        LoadState(StateMachine &sm, sf::RenderWindow &w, const bool isRepl);

        void update() override;
        void render() override;

        int load(std::string filename);
};