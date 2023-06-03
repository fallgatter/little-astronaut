//Cabeçalhos Próprios:
#include"../../include/Gerenciadores/Gerenciador_Eventos.h"

namespace Gerenciadores{
    Gerenciador_Eventos::Gerenciador_Eventos(Jogador *JOG, Vector2f POS, Vector2f VEL) : jog(JOG), pos(POS), vel(VEL)
    {
        if(jog){
            pos=jog->getPos();
            vel=jog->getVel();
        }
    }

    Gerenciador_Eventos::~Gerenciador_Eventos()
    {
        jog=NULL;
    }

    void Gerenciador_Eventos::gerenciarInput(sf::Event* evento){
        if(jog){
            if(Keyboard::isKeyPressed(Keyboard::A)){
                pos.x -= vel.x; 
                jog->setPos(Vector2f(pos));
            }
            else if(Keyboard::isKeyPressed(Keyboard::D)){
                pos.x += vel.x; 
                jog->setPos(pos);
            }
            else if(Keyboard::isKeyPressed(Keyboard::S)){
                pos.y += vel.y; 
                jog->setPos(pos);
            }
            else if(Keyboard::isKeyPressed(Keyboard::W)){
                pos.y -= vel.y; 
                jog->setPos(pos);
            }
        }
        if(Pjanela){
            if(Pjanela->isOpen()){}
                if (evento->type == sf::Event::Closed)
                    Pjanela->close();
                if (evento->type == sf::Event::Resized)
                    std::cout << evento->size.width << evento->size.height << std::endl;
        }
    }
    void Gerenciador_Eventos::setWindow(RenderWindow* jnl){
        Pjanela = jnl;
    }
};