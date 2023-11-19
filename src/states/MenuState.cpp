#include "States.hpp"

MenuState::MenuState(StateMachine &sm, sf::RenderWindow &w, const bool isRepl) : 
State {sm, w, isRepl}, 
executeBtn {Button("Executar", {220, 80}, 30, sf::Color(162, 197, 121), sf::Color::White)},
loadBtn {Button("Carregar", {220, 80}, 30, sf::Color(97, 163, 186), sf::Color::White)},
stepBtn {Button("Passo a Passo", {220, 80}, 30, sf::Color(97, 163, 186), sf::Color::White)},
returnBtn {Button("< Sair", {120, 70}, 12, sf::Color::Black, sf::Color::White)}  
{

    if (!font.loadFromFile("font.ttf") ) return;
   
    executeBtn.setFont(font);
    executeBtn.setPosition({300, 200});

    loadBtn.setFont(font);
    loadBtn.setPosition({300, 370});

    stepBtn.setFont(font);
    stepBtn.setPosition({300, 540});

    returnBtn.setFont(font);
    returnBtn.setPosition({10, 10});
    
}



void MenuState::update() {
    for (auto event = sf::Event{}; window.pollEvent(event);)
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				state_machine.Quit();
				break;

			case sf::Event::MouseButtonPressed:
                if (executeBtn.isMouseOver(window)) 
                    next_state = StateMachine::build<ExecutingState>(state_machine, window, false);
                //else if (stepBtn.isMouseOver(window))
                    //next_state = StateMachine::build<State>(state_machine, window, false);
                else if (loadBtn.isMouseOver(window))
                    next_state = StateMachine::build<LoadState>(state_machine, window, false);
                else if (returnBtn.isMouseOver(window)) //voltar no menu = sair
                    state_machine.Quit();
            break;
				

			default:
				break;
		}
	}
}

void MenuState::render() {

    window.clear();
    executeBtn.draw(window);
    loadBtn.draw(window);
    stepBtn.draw(window);
    returnBtn.draw(window);
    window.display();
}