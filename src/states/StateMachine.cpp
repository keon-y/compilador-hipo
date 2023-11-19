#include "StateMachine.hpp"

StateMachine::StateMachine() : isRunning{ false } {}



void StateMachine::Initialize(std::unique_ptr<State> initial_state) {
    states.push(std::move(initial_state));
    isRunning = true;
 }


void StateMachine::Run() {
    if (!states.empty()) {
    //se tiver proximo (mudanca de telas), excluir o primeiro
        auto next = states.top()->getNext();
        if ( next ) { 
            states.pop(); //excluir o primeiro antes de dar push
            states.push(std::move(next));
        }
    }
}

void StateMachine::Update() {
    states.top()->update();
}

void StateMachine::Render() {
    states.top()->render();
}

void StateMachine::Quit() {
    isRunning = false;
    
}

bool StateMachine::isActive() const { return isRunning; }