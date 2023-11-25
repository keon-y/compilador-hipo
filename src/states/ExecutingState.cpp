#include "States.hpp"

#include "Colors.hpp"

#define MAX_MEMBLOCK_PER_LINE 10
#define MEMBLOCK_X_OFFSET 5
#define MEMBLOCK_Y_OFFSET 5

ExecutingState::ExecutingState(StateMachine &sm, sf::RenderWindow &w, const bool isRepl) : 
State {sm, w, isRepl}, 
returnBtn {Button(w, "< Voltar", {120, 70}, 12, black, white, black)},
ac{MemoryBlock(w, "AC", "+0000", {50, 50}, 12, 2, white, black, white)},
pc{MemoryBlock(w, "PC", "0", {50, 50}, 12, 2, white, black, white)},
ioBox{Textbox(w, {130, 60}, white, white, 13, black)},
isWaitingInput{false},
submitBtn{Button(w, "Enviar", {80, 40}, 12, light_green, white, dark_green)},
notif(Notification(w)),
blueTip{ColorTip(w, light_blue, {13,13}, "Lendo")},
redTip{ColorTip(w, light_red, {13,13}, "Escrevendo")},
greenTip{ColorTip(w, light_green, {13,13}, "Executando")},
purpleTip{ColorTip(w, purple, {13,13}, "PC")},
pauseBtn{Button(w, "Pausar", {240, 70}, 15, light_red, white, dark_red)},
paused{false}
{
    state_machine.getCPU().initializeMemory();
    if (!font.loadFromFile("font.ttf") ) return;

    for (int i = 0; i < 100; i++) 
        mem_map.push_back(MemoryBlock(w, std::to_string(i), state_machine.getCPU().getStrMemoryAt(i), sf::Vector2f(50, 50), 12, 2, white, black, white));
    
    
    float x0_pos = 120 + (window.getSize().x - ((10 * mem_map[0].getSize() + MEMBLOCK_X_OFFSET) - MEMBLOCK_X_OFFSET)) / 2; //descobrir o x0 ideal para centralizar os 10 elementos
    for (int i = 0; i < (int)mem_map.size(); i++) {
            
        int current_inline = (i % MAX_MEMBLOCK_PER_LINE); //quantos blocos tem na linha que esta sendo desenhada
        int yLevel = i / MAX_MEMBLOCK_PER_LINE; //Qual a altura da linha desenhada (comeca em 0)

        float xPos = x0_pos + mem_map[i].getSize() * current_inline + MEMBLOCK_X_OFFSET * current_inline; 
        float yPos = 100 + mem_map[i].getSize() * yLevel + yLevel * MEMBLOCK_Y_OFFSET;
            
            
        mem_map[i].setFont(font);
        mem_map[i].setPosition({xPos, yPos});
           
    }

    ac.setFont(font);
    pc.setFont(font);
    ac.setPosition({80, 150});
    pc.setPosition({180, 150});

    state_machine.getCPU().setRunning(true);

    mem_map[0].setBorderColor(light_green);

    returnBtn.setFont(font);
    returnBtn.setPosition({10, 10});

    ioBox.setFont(font);
    ioBox.setPosition({120, 300});

    submitBtn.setFont(font);
    submitBtn.setPosition({220, 280});
    submitBtn.setActive(false);

    consoleTxt.setFont(font);
    consoleTxt.setCharacterSize(20);
    consoleTxt.setString("Console");
    consoleTxt.setFillColor(white);
    consoleTxt.setPosition({80, 245});

    notif.setFont(font);

    blueTip.setFont(font);
    blueTip.setPosition({30, 600});

    redTip.setFont(font);
    redTip.setPosition({30, 630});

    greenTip.setFont(font);
    greenTip.setPosition({30, 660});

    purpleTip.setFont(font);
    purpleTip.setPosition({30, 690});

    pauseBtn.setFont(font);
    pauseBtn.setPosition({60, 400});


}

void ExecutingState::update() {
    
    CPU &cpu = state_machine.getCPU();
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
                else if (pauseBtn.isMouseOver()) {
                    //pausou
                    if (state_machine.getCPU().isRunning()) {
                        pauseBtn.setText("Voltar");
                        pauseBtn.setBgColor(light_green, dark_green);
                        paused = true;
                    } else {
                        pauseBtn.setText("Pausar");
                        pauseBtn.setBgColor(light_red, dark_red);
                        paused = false;
                    }
                    state_machine.getCPU().setRunning(!paused);
                }
                else if (ioBox.isMouseOver() && isWaitingInput) {
                    ioBox.setSelected(ioBox.isMouseOver());
                }
                else if (submitBtn.isMouseOver() && isWaitingInput) {
                    //validar o input
                    input = ioBox.getText();
                    if (input.size() != 5 || (input[0] != '-' && input[0] != '+')) {
                        notif.notify("Numero no formato errado, formato correto: +XXXX ou -XXXX", 2);
                        break;
                    }
                    for (int i = 1; i < 5; i++) {
                        if (int(input[i]) < 48 || int(input[i]) > 57) {
                            notif.notify("Valor nao numerico inserido, formato correto: +XXXX ou -XXXX", 2);
                            break;
                        }
                    }
                    isWaitingInput = false;
                    submitBtn.setActive(false);
                    //pegar o endereco apontado pelo PC, achar os 2 ultimos digitos e mudar o valor
                    //armazenado nesse endereco (os ultimos 2 digitos)
                    cpu.getAddress(cpu.getAddress(cpu.getPC())->getNumericHalf())->operator=(input);
                    cpu.updatePC();

                    ioBox.setText("");
                }
            break;

             case sf::Event::TextEntered:
                if (std::isprint(event.text.unicode) && ioBox.isSelected() && isWaitingInput)
                    ioBox.addChar(event.text.unicode);
            break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::BackSpace && ioBox.isSelected() && isWaitingInput) 
                    ioBox.pop();
                if (event.key.code == sf::Keyboard::Enter && isWaitingInput) {
                     //validar o input
                    input = ioBox.getText();
                    if (input.size() != 5 || (input[0] != '-' && input[0] != '+')) {
                        notif.notify("Numero no formato errado (exemplo correto: +1421)", 2);
                        break;
                    }
                    for (int i = 1; i < 5; i++) {
                        if (int(input[i]) < 48 || int(input[i]) > 57) {
                            notif.notify("Valor nao numerico inserido", 2);
                            break;
                        }
                    }
                    isWaitingInput = false;
                    submitBtn.setActive(false);
                    //pegar o endereco apontado pelo PC, achar os 2 ultimos digitos e mudar o valor
                    //armazenado nesse endereco (os ultimos 2 digitos)
                    cpu.getAddress(cpu.getAddress(cpu.getPC())->getNumericHalf())->operator=(input);
                    cpu.updatePC();

                    ioBox.setText("");
                }
            break;

			default:
				break;
		}
	}

    if(notif.notifying()) 
        notif.move();
    

    if (isWaitingInput && ioBox.isSelected()) 
        ioBox.update();

    

    if (!state_machine.getCPU().isRunning() || isWaitingInput ) {
        if (!paused) execute_time = sf::seconds(2.9f);
        clock.restart(); //ficar reiniciando o tempo para nao acelerar depois de aceitar um input
        return;
    }

    execute_time += clock.restart();
    unsigned int i_pc = state_machine.getCPU().getPC();
    /*
    TRES PARTES:
        1. Ler a instrução que está na posição de memória indicada pelo apontador de instrução.
        2. Mudar o apontador de instrução para a posição de memória seguinte.
        3. Interpretar e executar a instrução lida.
    
    */
   
    mem_map[i_pc].setBorderColor(purple); //pintar onde o PC aponta
    
    //1: pintar PC de azul para sinalizar a leitura
    if (execute_time >= sf::seconds(3.0f)){

        //RESETAR AS CORES
        ac.setBorderColor(white);
        pc.setBorderColor(white);
        ioBox.setBorderColor(white);
        for (int i = 0; i < 100; i++) { //pintar todos de branco exceto o PC (sendo executado) e PC + 1 (onde pc aponta)
            mem_map[i].setText(cpu.getStrMemoryAt(i));
            mem_map[i].setBorderColor(white);
        }
        

        mem_map[i_pc].setBorderColor(light_blue);
    }

    //2: pintar o prox de roxo para sinalizar o avanco do PC
    if (execute_time >= sf::seconds(5.0f)){
        mem_map[i_pc + 1].setBorderColor(purple);
        pc.setText(std::to_string(i_pc + 1)); //setar o PC temporariamente aqui para mostrar em cima
    }

    //3: pintar de VERDE para sinalizar execucao e pintar valores sendo lidos/escritos etc
    if(execute_time >= sf::seconds(7.0f)) { 
        std::string opcode = cpu.getAddress(i_pc)->getFirstHalf();
        if (opcode == "11") { //AC recebe END
            ac.setBorderColor(light_red);
            mem_map[cpu.getAddress(i_pc)->getNumericHalf()].setBorderColor(light_blue);
        }
        else if(opcode == "12") { //END recebe AC
            ac.setBorderColor(light_blue);
            mem_map[cpu.getAddress(i_pc)->getNumericHalf()].setBorderColor(light_red);
        }
        //se for uma operacao aritmetica, sempre vai ler o segundo valor
        else if (opcode[0] == '2') {
            ac.setBorderColor(light_red);
            mem_map[cpu.getAddress(i_pc)->getNumericHalf()].setBorderColor(light_blue);
        }
        else if (opcode == "31") { //leitura
            mem_map[cpu.getAddress(i_pc)->getNumericHalf()].setBorderColor(light_red);
            ioBox.setBorderColor(light_blue);
        }
        else if(opcode == "41") { //escrita
            mem_map[cpu.getAddress(i_pc)->getNumericHalf()].setBorderColor(light_blue);
            ioBox.setBorderColor(light_red);
        }
        else if (opcode[0] == '5') { //branches
            //pintar de branco onde PC aponta, pois em caso de branch ficariam 2 magentas ate todos os blocos forem recoloridos
            mem_map[i_pc+1].setBorderColor(white);
            mem_map[cpu.getAddress(i_pc)->getNumericHalf()].setBorderColor(light_blue);
            pc.setBorderColor(light_red);
        }
        else if(opcode[0] == '6') { //shifts
            ac.setBorderColor(light_red);
        }
        mem_map[i_pc].setBorderColor(light_green);

        //HANDLER PARA RESULTADOS DA CPU

        switch(cpu.execute()) {
            case -1: //instrucao inexistente
                mem_map[i_pc].setBorderColor(white);
                mem_map[i_pc + 1].setBorderColor(white);
                cpu.setRunning(false);
                notif.notify("Instrucao nao encontrada", 2);
            break;

            case 0: //encerrou (codigo 70)
                mem_map[i_pc].setBorderColor(white);
                mem_map[i_pc + 1].setBorderColor(white);
                notif.notify("Programa encerrado com sucesso!", 0);
            break;

            case 1: //aguardado leitura
                ioBox.setText(""); //limpar a caixa de IO
                isWaitingInput = true;
                notif.notify("Insira um valor na caixa do console", 1);
                submitBtn.setActive(true);
            break;

            case 2: //escrever
                /*codigo extenso que faz o seguinte:
                    encontra o pc -> encontra a memoria que ele aponta -> 
                    pega a segunda metade da memoria que o PC aponta ->
                    pega a memoria que a segunda metade aponta ->
                    pega o conteudo
                
                */
                ioBox.setText(cpu.getAddress(cpu.getAddress(cpu.getPC())->getNumericHalf())->toString());
                
                cpu.updatePC();
            break;

            case 3: //instrucao executada

            break;
        }


        ac.setText(cpu.getAC().toString());
        pc.setText(std::to_string(cpu.getPC()));
        execute_time = sf::Time::Zero;
    }


}

void ExecutingState::render() {
    
    window.clear(black);
    
    for (int i = 0; i < 100; i++)
        mem_map[i].draw();
    ac.draw();
    pc.draw();
    returnBtn.draw();
    ioBox.draw();

    submitBtn.draw();

    window.draw(consoleTxt);
    if(notif.notifying())
        notif.draw();

    blueTip.draw();
    redTip.draw();
    greenTip.draw();
    purpleTip.draw();

    pauseBtn.draw();

    window.display();
}