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
        Inimigo::Inimigo(Vector2f POs) : Personagem(POs){
            Texture txt;
            Sprite spr;
            txt.loadFromFile("assets\\textures\\Player\\gato.png");
            spr.setTexture(txt);
            setSprite(spr);
            id = 'i';
        }
        void Inimigo::colidir(Entidade* outro, Vector2f ds){
            if(outro->getId()=='o'){//objeto
                
            }
            else if(outro->getId()=='j'){//jogador
                Vector2f vjog = getVel(), voutro=outro->getVel();
                
                /*vjog.x = vjog.x/2 + 0.0001;
                vjog.y = vjog.y/2 + 0.0001;
                setVel(vjog);
                vjog.x = -vjog.x - 0.0001;
                vjog.y = -vjog.y - 0.0001;
                outro->setVel(vjog);*/

                if(ds.x>ds.y){
                    if(outro->getPos().x<getPos().x){
                        vjog.x-=0.0001;
                        voutro.x+=0.0001;
                    }
                    else{
                        vjog.x+=0.0001;
                        voutro.x-=0.0001;
                    }
                }
                else{
                    if(outro->getPos().y<getPos().y){
                        vjog.y-=0.0001;
                        voutro.y+=0.0001;
                    }
                    else{
                        vjog.y+=0.0001;
                        voutro.y-=0.0001;
                    } 
                }
                setVel(voutro);
                outro->setVel(vjog);
            }
            else if(outro->getId()=='i'){//inimigo

            }
        }
        void Inimigo::testemov(){
            vel.x = vel.x - 0.0000;
        }
    };
};