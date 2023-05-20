#include"../../include/Gerenciadores/Eventos.h"

namespace Gerenciadores{
    Eventos::Eventos(Jogador* JOG, Vector2f POS, Vector2f VEL):
        jog(JOG), pos(POS), vel(VEL)
    {
        pos=jog->getPos();
        vel=jog->getVel();
    }

    Eventos::~Eventos()
    {
        jog=NULL;
    }

    void Eventos::gerenciarInput(){
        if(Keyboard::isKeyPressed(Keyboard::A)){
            pos.x -= vel.x; 
            jog->setcord(Vector2f(pos));
        }
        else if(Keyboard::isKeyPressed(Keyboard::D)){
            pos.x += vel.x; 
            jog->setcord(pos);
        }
        else if(Keyboard::isKeyPressed(Keyboard::S)){
            pos.y += vel.y; 
            jog->setcord(pos);
        }
        else if(Keyboard::isKeyPressed(Keyboard::W)){
            pos.y -= vel.y; 
            jog->setcord(pos);
        }
    }
};