//Cabeçalhos Próprios:
#include"../../include/Gerenciadores/Gerenciador_Eventos.h"

namespace Gerenciadores{
    Gerenciador_Eventos* Gerenciador_Eventos::P=NULL;

    Gerenciador_Eventos::Gerenciador_Eventos(Jogador *JOG): jog(JOG)
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
        jog=NULL;
    }

    void Gerenciador_Eventos::setJog(Jogador* JOG){
        jog=JOG;
    }

    void Gerenciador_Eventos::executar(){
        Event evento;

        while(Ga->getWindow()->pollEvent(evento)){
            Vector2f vel=jog->getVel();
            int energ=jog->getEnerg();
            if(jog){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && jog->getEnerg()){
                    vel.y += -0.2;
                    jog->setEnerg(energ--);
                }
                if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && jog->getEnerg()<100){
                    jog->setEnerg(energ++);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    vel.x += 0.1;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    vel.x -= 0.21;
                }
                jog->setVel(vel);
            }
            if(Ga->getWindow()){
                if(Ga->isopen()){}
                    if (evento.type == sf::Event::Closed)
                        Ga->closeWindow();
            }
        }
    }
};