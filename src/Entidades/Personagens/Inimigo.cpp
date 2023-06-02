//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Inimigo.h"

namespace Entidades{
    namespace Personagens{
        Inimigo::Inimigo(Vector2f POS): 
            Personagem(5.0, 1.0, Vector2f(38.f, 48.f), POS, 'i')
        {
            Sprite sprtemp;
            text.loadFromFile("assets\\textures\\Enemies\\green_alien.png");
            sprtemp.setTexture(text);
            setSprite(sprtemp);
        }
        
        Inimigo::~Inimigo(){
        }
        
        void Inimigo::colidir(Entidade* outro, Vector2f ds){
            if(outro->getId()=='o'){//objeto
                
            }
            else if(outro->getId()=='j'){//jogador
                cout<<"COLISAOi->j"<<endl;
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
    };
};