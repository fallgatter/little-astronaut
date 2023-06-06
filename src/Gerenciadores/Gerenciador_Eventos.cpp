//Cabeçalhos Próprios:
#include"../../include/Gerenciadores/Gerenciador_Eventos.h"

namespace Gerenciadores{
    Gerenciador_Eventos* Gerenciador_Eventos::P=NULL;

    Gerenciador_Eventos::Gerenciador_Eventos()
    {
        Ga=Ga->Singleton();
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

        while(Ga->getWindow()->pollEvent(evento)){
            if(Ga->getWindow()){
                if(Ga->isopen()){}
                    if (evento.type == sf::Event::Closed)
                        Ga->closeWindow();
            }
        }
    }
};