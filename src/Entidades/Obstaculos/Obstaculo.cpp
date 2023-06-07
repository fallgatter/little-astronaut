//Cabeçalhos Próprios:
#include"../../../include/Entidades/Obstaculos/Obstaculo.h"

namespace Obstaculos{
    Obstaculo::Obstaculo(Vector2f POS, bool DANOSO, int ID): 
        Entidade(0, true, Vector2f(48.f, 48.f), POS, ID), danoso(DANOSO)
    {
        if(danoso)
            setDano(10);
    }

    Obstaculo::~Obstaculo(){

    }

    void Obstaculo::colidir(Entidade* outro, Vector2f ds){
        if(outro->getId()!='b' && outro->getId()!='p'){
            Vector2f posAux=outro->getPos();  
            if(ds.x>ds.y){
                if(outro->getPos().x<getPos().x)//colisão em x
                    posAux.x+=ds.x;
                else
                    posAux.x-=ds.x;
                outro->setVel(Vector2f(0.f, outro->getVel().y));
            }
            else{
                if(outro->getPos().y<getPos().y)
                    posAux.y+=ds.y;
                else
                    posAux.y-=ds.y;
                outro->setVel(Vector2f(outro->getVel().x, 0.f));
            }
            outro->setPos(posAux);
        }
        if(outro->getId() == 'p'){
            outro->setVivo(false);
        }
    }
};