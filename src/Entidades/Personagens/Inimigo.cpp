//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Inimigo.h"

namespace Entidades{
    namespace Personagens{
        Inimigo::Inimigo(float VIDA, float DANO, Vector2f TAM, Vector2f POS, Vector2f VEL, Vector2f ACEL, Texture TEXT, Sprite SPRT, int ID): 
            Personagem(VIDA, DANO, TAM, POS, VEL, ACEL, TEXT, SPRT, ID)
        {
        }

        Inimigo::~Inimigo(){
        }
        void Inimigo::colidir(Entidade* outro){
            if(outro->getId()=='o'){//objeto
                
            }
            else if(outro->getId()=='j'){//inimigo
                
                Vector2f vaux = getVel(), vpos = getPos(), voutropos = outro->getPos();
                vaux.x = -vaux.x/2 + 0.0001;
                vaux.y = -vaux.y/2 + 0.0001;
                setPos(Vector2f(getPos().x + vaux.x*1,getPos().y + vaux.y*1));
                setVel(vaux);
                vaux.x = -vaux.x - 0.0001;
                vaux.y = -vaux.y - 0.0001;
                outro->setVel(vaux);
                outro->setPos(Vector2f(voutropos.x + vaux.x*100,voutropos.y + vaux.y*100));
                vpos.x = getPos().x + (getPos().x -  outro->getPos().x)/5;
                vpos.y = getPos().y;
                setPos(vpos);
            }
            else if(outro->getId()=='i'){//jogador

            }
        }
        void Inimigo::testemov(){
            vel.x = vel.x - 0.0000;
        }
    };
};