#include "States.hpp"
#include <fstream>
#include <vector>
#include "Colors.hpp"

LoadState::LoadState(StateMachine &sm, sf::RenderWindow &w, const bool isRepl) : 
State {sm, w, isRepl},
returnBtn {Button(w, "< Voltar", {120, 70}, 12, black, white, black)},
textbox {Textbox(w, {300, 80}, white, white, 20, black)},
submitBtn {Button(w, "Carregar", {200, 70}, 18, light_blue, white, dark_blue)}, 
notif{Notification(w)}
{
    if (!font.loadFromFile("font.ttf") ) return;
    returnBtn.setFont(font);
    returnBtn.setPosition({10, 10});


    textbox.setFont(font);
    sf::Vector2u pos = window.getSize();
    textbox.setPosition({pos.x/2.0f, pos.y/2.0f}); //centralizar na tela

    submitBtn.setFont(font);
    submitBtn.setPosition({pos.x/2.0f - 100, pos.y/2.0f + 100});

    notif.setFont(font);
}


void LoadState::render() {
    
    window.clear(black);
    
    returnBtn.draw();
    textbox.draw();
    submitBtn.draw();

    if (notif.notifying()) {
        notif.draw();
    }

    window.display();


}

void LoadState::update() {
    sf::Clock clock;
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
                else {
                    

                    textbox.setSelected(textbox.isMouseOver());
                    if (submitBtn.isMouseOver()) {
                        int loadState = load(textbox.getText());
                        switch(loadState) {
                            case 0:
                                notif.notify("Arquivo carregado com sucesso!", 0);
                            break;
                            case -1:
                                notif.notify("Arquivo nao encontrado!", 2);
                            break;
                            case -2:
                                notif.notify("Algum valor com mais ou menos de 5 digitos!", 2);
                            break;
                            case -3:
                                notif.notify("Algum valor nao inicia com + ou -", 2);
                            break;
                            case -4:
                                notif.notify("Algum valor nao numerico no arquivo!", 2);
                            break;

                        }
                            
                    }
                }
        
            break;

            case sf::Event::TextEntered:
                if (std::isprint(event.text.unicode) && textbox.isSelected())
                    textbox.addChar(event.text.unicode);
            break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::BackSpace && textbox.isSelected()) 
                    textbox.pop();
                
            
            break;

			default:
				break;
		}
	}

    //animacoes
    if(notif.notifying()) //animacao da notificacao
        notif.move();

    
    if(textbox.isSelected())
        textbox.update();
}

int LoadState::load(std::string filename){


    std::ifstream file(filename);
    if (!file.is_open()) //nao encontrou
        return -1;
    
    std::vector<std::string> v;
    std::string read;
    
    
    while(file.good()) {
        file >> read;
        //checar os digitos e o tamanho para ver se esta no formato certo
        if (read.size() != 5) {
            file.close();
            return -2;
        }
        if (read[0] != '-' && read[0] != '+' ) {
            file.close();   
            return -3;
        }
        for (int i = 1; i < 5; i++) {
            if (int(read[i]) < 48 || int(read[i]) > 57) {
                file.close();
                return -4;
            }
        }
        v.push_back(read);
    }

    for (int i = v.size(); i < 100; i++) { //completar com +0000 o resto
        v.push_back("0");
    }
    state_machine.getCPU().resetMemory(); //limpar a memoria caso tenha algo
    for(int i = 0; i < (int)v.size(); i++) { //adicionar na memoria da cpu
    
        state_machine.getCPU().addToMemory((Integer)v[i]);
    }
    file.close();
    return 0;
}