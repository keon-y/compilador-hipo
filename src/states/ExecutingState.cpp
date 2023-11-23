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

    state_machine.getCPU().setRunning(true);

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
    if (!state_machine.getCPU().isRunning()) return;

    execute_time += clock.restart();
    /*
            CORES: verde = instrucao sendo lida
                   azul  = valor sendo lido
                   vermelho = valor sendo sobrescrevido
                   ciano = executando
                   magenta = apontado pelo pc

        
        */
    unsigned int i_pc = state_machine.getCPU().getPC();
    /*
    TRES PARTES:
        1. Ler a instrução que está na posição de memória indicada pelo apontador de instrução.
        2. Mudar o apontador de instrução para a posição de memória seguinte.
        3. Interpretar e executar a instrução lida.
    
    */

    mem_map[i_pc].setBorderColor(sf::Color::Magenta); //pintar onde o PC aponta
    
    //1: pintar PC de azul para sinalizar a leitura
    if (execute_time >= sf::seconds(3.0f)){

        //RESETAR AS CORES
        ac.setBorderColor(sf::Color::White);
        pc.setBorderColor(sf::Color::White);
        for (int i = 0; i < 100; i++) { //pintar todos de branco exceto o PC (sendo executado) e PC + 1 (onde pc aponta)
            mem_map[i].setText(state_machine.getCPU().getStrMemoryAt(i));
            mem_map[i].setBorderColor(sf::Color::White);
        }
        

        mem_map[i_pc].setBorderColor(sf::Color::Blue);
    }

    //2: pintar o prox de magenta para sinalizar o avanco do PC
    if (execute_time >= sf::seconds(5.0f)){
        mem_map[i_pc + 1].setBorderColor(sf::Color::Magenta);
        pc.setText(std::to_string(i_pc + 1)); //setar o PC temporariamente aqui para mostrar em cima
    }

    //3: pintar de CIANO para sinalizar execucao e pintar valores sendo lidos/escritos etc
    if(execute_time >= sf::seconds(7.0f)) { 
        
        if (state_machine.getCPU().getAddress(i_pc)->getFirstHalf() == "11") {
            ac.setBorderColor(sf::Color::Red);
            mem_map[state_machine.getCPU().getAddress(i_pc)->getNumericHalf()].setBorderColor(sf::Color::Blue);
        }
        else if (state_machine.getCPU().getAddress(i_pc)->getFirstHalf() == "21") {
            ac.setBorderColor(sf::Color::Red);
            mem_map[state_machine.getCPU().getAddress(i_pc)->getNumericHalf()].setBorderColor(sf::Color::Blue);
        }
        mem_map[i_pc].setBorderColor(sf::Color::Cyan);
        state_machine.getCPU().execute();
        ac.setText(state_machine.getCPU().getAC().toString());
        pc.setText(std::to_string(state_machine.getCPU().getPC()));
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