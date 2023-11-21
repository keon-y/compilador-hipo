#include "State.hpp"
#include "States.hpp"

State::State(StateMachine &sm, sf::RenderWindow &w, const bool isRepl)
: state_machine {sm}, window {w}, replacing {isRepl}
{ }

// o getNext() sera vazio ate um proximo estado existir (por algum evento)
std::unique_ptr<State> State::getNext() {
    return std::move(next_state);
}

bool State::isReplacing() const {
    return replacing;
}