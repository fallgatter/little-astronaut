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

    void Gerenciador_Eventos::controlarJog(Jogador* jog){
        Vector2f vel=jog->getVel();
        int energ=jog->getEnerg();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && energ){
            vel.y += -0.2;
            energ--;
        }
        if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && energ<100){
            energ++;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            vel.x += 0.1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            vel.x -= 0.21;
        }
        jog->setVel(vel);
        jog->setEnerg(energ);
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