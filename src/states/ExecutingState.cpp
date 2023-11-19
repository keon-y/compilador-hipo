#include "States.hpp"

#define MAX_MEMBLOCK_PER_LINE 10
#define MEMBLOCK_X_OFFSET 5
#define MEMBLOCK_Y_OFFSET 20
#define MEMBLOCK_PADDING_SIDE 30
#define MEMBLOCK_PADDING_TOP 100

ExecutingState::ExecutingState(StateMachine &sm, sf::RenderWindow &w, const bool isRepl) : 
State {sm, w, isRepl}, 
returnBtn {Button("< Voltar", {120, 70}, 12, sf::Color::Black, sf::Color::White)} 
{
    if (!font.loadFromFile("font.ttf") ) return;

    for (int i = 0; i < 100; i++) 
        memMap.push_back(MemoryBlock(i, "+0000", sf::Vector2f(50, 50), 12, 2, sf::Color::White, sf::Color::Black, sf::Color::White));
    
    
    float x0_pos = (window.getSize().x - ((10 * memMap[0].getSize() + MEMBLOCK_X_OFFSET) - MEMBLOCK_X_OFFSET)) / 2; //descobrir o x0 ideal para centralizar os 10 elementos
    for (int i = 0; i < memMap.size(); i++) {
            
        int current_inline = (i % MAX_MEMBLOCK_PER_LINE); //quantos blocos tem na linha que esta sendo desenhada
        int yLevel = i / MAX_MEMBLOCK_PER_LINE; //Qual a altura da linha desenhada (comeca em 0)

        float xPos = x0_pos + memMap[i].getSize() * current_inline + MEMBLOCK_X_OFFSET * current_inline; 
        float yPos = 100 + memMap[i].getSize() * yLevel + yLevel * MEMBLOCK_Y_OFFSET;
            
            
        memMap[i].setFont(font);
        memMap[i].setPosition({xPos, yPos});
           
    }

    returnBtn.setFont(font);
    returnBtn.setPosition({10, 10});
}

void ExecutingState::update() {
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

void ExecutingState::render() {
    
    window.clear();
    
    for (int i = 0; i < 100; i++)
        memMap[i].draw(window);

    returnBtn.draw(window);

    window.display();
}
