#include "States.hpp"

#define MAX_MEMBLOCK_PER_LINE 10
#define MEMBLOCK_X_OFFSET 5
#define MEMBLOCK_Y_OFFSET 5

ExecutingState::ExecutingState(StateMachine &sm, sf::RenderWindow &w, const bool isRepl) : 
State {sm, w, isRepl}, 
returnBtn {Button(w, "< Voltar", {120, 70}, 12, sf::Color::Black, sf::Color::White)},
ac{MemoryBlock(w, "AC", "+0000", {50, 50}, 12, 2, sf::Color::White, sf::Color::Black, sf::Color::White)},
pc{MemoryBlock(w, "PC", "0", {50, 50}, 12, 2, sf::Color::White, sf::Color::Black, sf::Color::White)}
{
    if (!font.loadFromFile("font.ttf") ) return;

    for (int i = 0; i < 100; i++) 
        mem_map.push_back(MemoryBlock(w, std::to_string(i), state_machine.getCPU().getStrMemoryAt(i), sf::Vector2f(50, 50), 12, 2, sf::Color::White, sf::Color::Black, sf::Color::White));
    
    
    float x0_pos = (window.getSize().x - ((10 * mem_map[0].getSize() + MEMBLOCK_X_OFFSET) - MEMBLOCK_X_OFFSET)) / 2; //descobrir o x0 ideal para centralizar os 10 elementos
    for (int i = 0; i < mem_map.size(); i++) {
            
        int current_inline = (i % MAX_MEMBLOCK_PER_LINE); //quantos blocos tem na linha que esta sendo desenhada
        int yLevel = i / MAX_MEMBLOCK_PER_LINE; //Qual a altura da linha desenhada (comeca em 0)

        float xPos = x0_pos + mem_map[i].getSize() * current_inline + MEMBLOCK_X_OFFSET * current_inline; 
        float yPos = 100 + mem_map[i].getSize() * yLevel + yLevel * MEMBLOCK_Y_OFFSET;
            
            
        mem_map[i].setFont(font);
        mem_map[i].setPosition({xPos, yPos});
           
    }

    ac.setFont(font);
    pc.setFont(font);
    ac.setPosition({300, 50});
    pc.setPosition({370, 50});

    mem_map[0].setBorderColor(sf::Color::Green);

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
                if (returnBtn.isMouseOver()) 
                    state_machine.resume();		
            break;

			default:
				break;
		}
	}
    execute_time += clock.restart();
    if(execute_time >= sf::seconds(5.0f)) {
        

         for (int i = 0; i < 100; i++) {
            mem_map[i].setText(state_machine.getCPU().getStrMemoryAt(i));
            if(i == state_machine.getCPU().getPC()) mem_map[i].setBorderColor(sf::Color::Green);
            else mem_map[i].setBorderColor(sf::Color::White);

            if (state_machine.getCPU().getAddress(i)->getFirstHalf() == "11" && i == state_machine.getCPU().getPC())
                mem_map[state_machine.getCPU().getAddress(i)->getNumericHalf()].setBorderColor(sf::Color::Blue);
            else if (state_machine.getCPU().getAddress(i)->getFirstHalf() == "21" && i == state_machine.getCPU().getPC())
                mem_map[state_machine.getCPU().getAddress(i)->getNumericHalf()].setBorderColor(sf::Color::Blue);
            //else mem_map[i].setBorderColor(sf::Color::White);
            

         }
         ac.setText(state_machine.getCPU().getAC().toString());
         pc.setText(std::to_string(state_machine.getCPU().getPC()));
        state_machine.getCPU().execute();
        execute_time = sf::Time::Zero;
    }
}

void ExecutingState::render() {
    
    window.clear();
    
    for (int i = 0; i < 100; i++)
        mem_map[i].draw();
    ac.draw();
    pc.draw();
    returnBtn.draw();

    window.display();
}
