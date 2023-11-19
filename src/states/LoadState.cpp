#include "States.hpp"

LoadState::LoadState(StateMachine &sm, sf::RenderWindow &w, const bool isRepl) : 
State {sm, w, isRepl},
returnBtn {Button("< Voltar", {120, 70}, 12, sf::Color::Black, sf::Color::White)} 
{
    if (!font.loadFromFile("font.ttf") ) return;
    returnBtn.setFont(font);
    returnBtn.setPosition({10, 10});
}


void LoadState::render() {
    
    window.clear();
    
    returnBtn.draw(window);

    window.display();

}

void LoadState::update() {
    for (auto event = sf::Event{}; window.pollEvent(event);)
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				state_machine.Quit();
				break;

            case sf::Event::MouseButtonPressed:
                if (returnBtn.isMouseOver(window)) 
                    next_state = StateMachine::build<MenuState>(state_machine, window, false);	
            break;
			default:
				break;
		}
	}
}