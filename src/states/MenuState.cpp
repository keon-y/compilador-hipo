#include "States.hpp"
#include "Colors.hpp"

MenuState::MenuState(StateMachine &sm, sf::RenderWindow &w, const bool isRepl) : 
State {sm, w, isRepl}, 
executeBtn {Button(w, "Executar", {220, 80}, 30, light_green, white, dark_green)},
loadBtn {Button(w, "Carregar", {220, 80}, 30, light_blue, white, dark_blue)},
returnBtn {Button(w, "< Sair", {120, 70}, 12, black, white, black)}  
{

    if (!font.loadFromFile("font.ttf") ) return;
   
    executeBtn.setFont(font);
    executeBtn.setPosition({window.getSize().x / 2.0f - 110, 350});

    loadBtn.setFont(font);
    loadBtn.setPosition({window.getSize().x / 2.0f - 110, 500});


    returnBtn.setFont(font);
    returnBtn.setPosition({10, 10});
    
    txt.setFont(font);
    txt.setFillColor(white);
    txt.setCharacterSize(30);
    txt.setString("Compilador HIPO");
    txt.setOrigin({txt.getGlobalBounds().width/2, txt.getGlobalBounds().height/2 });
    txt.setPosition({window.getSize().x/2.0f, 250});

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
                if (executeBtn.isMouseOver()) 
                    next_state = StateMachine::build<ExecutingState>(state_machine, window, false);
                else if (loadBtn.isMouseOver())
                    next_state = StateMachine::build<LoadState>(state_machine, window, false);
                else if (returnBtn.isMouseOver()) //voltar no menu = sair
                    state_machine.Quit();
            break;
				

			default:
				break;
		}
	}

}

void MenuState::render() {

    window.clear(black);
    executeBtn.draw();
    loadBtn.draw();
    returnBtn.draw();
    window.draw(txt);
    window.display();
}