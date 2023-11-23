#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class StateMachine;

class State {

    protected:
        sf::Clock clock;
        StateMachine &state_machine;
        std::unique_ptr<State> next_state;
        sf::RenderWindow &window;
        bool replacing;

        

    public:
        State(StateMachine &sm, sf::RenderWindow &w, const bool isRepl);


        virtual void update() = 0; 
        virtual void render() = 0;

        bool isReplacing() const;

        std::unique_ptr<State> getNext();

        virtual ~State() = default;

        State(const State&) = delete;
        State& operator=(const State&) = delete;
};