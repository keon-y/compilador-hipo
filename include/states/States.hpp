#pragma once

#include "State.hpp"
#include "StateMachine.hpp"
#include "Button.hpp"
#include "MemoryBlock.hpp"

class MenuState : public State {
    sf::Font font;
    Button executeBtn;
    Button stepBtn;
    Button loadBtn;
    Button returnBtn;

    public:
        MenuState(StateMachine &sm, sf::RenderWindow &w, const bool isRepl);

        void update() override;
        void render() override;

};

class ExecutingState : public State {
    sf::Font font;
    std::vector<MemoryBlock> memMap;
    Button returnBtn;

    public:
        ExecutingState(StateMachine &sm, sf::RenderWindow &w, const bool isRepl);

        void update() override;
        void render() override;
};

class LoadState : public State {
    sf::Font font;
    Button returnBtn;
    public:
        LoadState(StateMachine &sm, sf::RenderWindow &w, const bool isRepl);

        void update() override;
        void render() override;
};