//Cabeçalhos Próprios:
#include"../../include/Gerenciadores/Gerenciador_Eventos.h"
#include"../../include/Menu/Menu_de_pause.h"

namespace Gerenciadores{
    Gerenciador_Eventos* Gerenciador_Eventos::P=NULL;

    Gerenciador_Eventos::Gerenciador_Eventos()
    {
        Ga=Ga->Singleton();
        pausa = 1;
    }

    Gerenciador_Eventos* Gerenciador_Eventos::Singleton(){
        if(P == NULL){
            P = new Gerenciador_Eventos();
        }
        return P;
    }

    Gerenciador_Eventos::~Gerenciador_Eventos(){
        
    }

    void Gerenciador_Eventos::executar(){
        Event evento;
        Menu_de_pause mp;
        if(Ga->getWindow() != NULL){
            while(Ga->getWindow()->pollEvent(evento)){
                if(Ga->getWindow()){
                    if(Ga->isopen()){}
                        if (evento.type == sf::Event::Closed)
                            Ga->closeWindow();
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ){
                            Ga->setViewPos(Vector2f(100.f,200.f));
                            if(mp.selecionar() == 2)
                                pausa = 0;
                            else if(mp.selecionar() == 0)
                                return;
                }
            }
        }
    }

    int Gerenciador_Eventos::selecionado_da_pausa(){
        return pausa;
    }
};