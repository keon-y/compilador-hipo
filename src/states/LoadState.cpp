#include "States.hpp"
#include <fstream>
#include <vector>

LoadState::LoadState(StateMachine &sm, sf::RenderWindow &w, const bool isRepl) : 
State {sm, w, isRepl},
returnBtn {Button(w, "< Voltar", {120, 70}, 12, sf::Color::Black, sf::Color::White)},
textbox {Textbox(w, {300, 80}, sf::Color::White, sf::Color::White, 20, sf::Color::Black)},
submitBtn {Button(w, "Carregar", {200, 70}, 18, sf::Color::Blue, sf::Color::White)}, 
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
    
    window.clear();
    
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
                                notif.setText("Arquivo carregado!");
                                notif.setBgColor(0);
                                notif.notify();
                            break;
                            case -1:
                                notif.setText("Arquivo nao encontrado!");
                                notif.setBgColor(2);
                                notif.notify();
                            break;
                            case -2:
                                notif.setText("Algum valor com mais ou menos de 5 digitos!");
                                notif.setBgColor(2);
                                notif.notify();
                            break;
                            case -3:
                                notif.setText("Algum valor nao inicia com + ou -");
                                notif.setBgColor(2);
                                notif.notify();
                            break;
                            case -4:
                                notif.setText("Algum valor nao numerico no arquivo!");
                                notif.setBgColor(2);
                                notif.notify();
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
    if(notif.notifying() || textbox.isSelected()) {
        auto temp = clock.restart();

        if (textbox.isSelected()) { //animacao da textbox
            text_effect_time += temp;

            if (text_effect_time >= sf::seconds(0.005f) ) {
                show_cursor = !show_cursor;
                text_effect_time = sf::Time::Zero;
            }
        }
        
        if(notif.notifying()) { //animacao da notificacao
            notification_effect_time += temp;

            if (notification_effect_time >= sf::seconds(0.00005f)) 
                notif.move(notification_effect_time);

        }
        
    }
    textbox.update(show_cursor);
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
        if (read.size() != 5) return -2;
        if (read[0] != '-' && read[0] != '+' ) return -3;
        for (int i = 1; i < 5; i++) {
            if (int(read[i]) < 48 || int(read[i]) > 57) return -4;
        }
        v.push_back(read);
    }

    for (int i = v.size(); i < 100; i++) { //completar com +0000 o resto
        v.push_back("0");
    }

    for(int i = 0; i < v.size(); i++) { //adicionar na memoria da cpu
        state_machine.getCPU().addToMemory((Integer)v[i]);
    }
    return 0;
}