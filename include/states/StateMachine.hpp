#pragma once

#include <memory>
#include <stack>
#include "State.hpp"



class StateMachine {
    public:
        StateMachine ();

        void Run();
        void Update();
        void Render();
        void Quit();

        bool isActive() const;

        void Initialize(std::unique_ptr<State> initial_state);
        
        template<typename T> 
        static std::unique_ptr<T> build(StateMachine &sm, sf::RenderWindow &w, bool isReplacing);


    private:
        bool isRunning;
	    std::stack<std::unique_ptr<State>> states;
};

template<typename T> 
std::unique_ptr<T> StateMachine::build(StateMachine &state_machine, sf::RenderWindow &window, bool isReplacing) {
    std::unique_ptr<T> new_state = std::make_unique<T>(state_machine, window, isReplacing);
    return new_state;
}