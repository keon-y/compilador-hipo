#include "StateMachine.hpp"

StateMachine::StateMachine(CPU& c) : isRunning{ false }, cpu{c} {}



void StateMachine::Initialize(std::unique_ptr<State> initial_state) {
    states.push(std::move(initial_state));
    isRunning = true;
 }


void StateMachine::Run() {

    //voltar a tela anterior
    if (isResuming && !states.empty()) {
        states.pop();
        isResuming = false;
    }


    if (!states.empty()) {
        auto next = states.top()->getNext();
        if (next) {
            if (next->isReplacing()) 
                states.pop(); //excluir caso for pra substituir
            
            states.push(std::move(next));
        }
    }
}

void StateMachine::resume() {
    isResuming = true;
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

CPU& StateMachine::getCPU() const {
    return cpu;
}

bool StateMachine::isActive() const { return isRunning; }