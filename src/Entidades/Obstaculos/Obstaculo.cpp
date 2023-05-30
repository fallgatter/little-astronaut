#include"../../../include/Entidades/Obstaculos/Obstaculo.h"
#include<math.h>

namespace Obstaculos{
    Obstaculo::Obstaculo(Vector2f TAM, Vector2f POS, Vector2f VEL, Vector2f ACEL, Texture TEXT, Sprite SPRT, int ID)  : Entidade(TAM, POS,  VEL, ACEL,TEXT, SPRT,ID){}
    Obstaculo::~Obstaculo(){}
    void Obstaculo::colidir(Entidade* outro, Vector2f ds){
        if(outro->getId()!='o'){
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
                outro->setVel(Vector2f( outro->getVel().x, 0.f));
            }
            outro->setPos(posAux);
        }
    }
} using namespace Obstaculos;