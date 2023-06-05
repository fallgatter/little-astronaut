//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Inimigo.h"

namespace Entidades{
    namespace Personagens{
        Jogador* Inimigo::jog(NULL);
        
        Inimigo::Inimigo(Vector2f POS, int ID): 
            Personagem(5.0, 1.0, Vector2f(38.f, 48.f), POS, ID)
        {
            
        }
        
        Inimigo::~Inimigo(){
        }

        void Inimigo::colidir(Entidade* outro, Vector2f ds){
            if(outro->getId()=='b'){//objeto
                
            }
            else if(outro->getId()=='j'){//jogador
                Vector2f vjog = getVel(), voutro=outro->getVel();
                if(ds.x>ds.y){
                    if(outro->getPos().x<getPos().x){
                        vjog.x-=0.5;
                        voutro.x+=0.5;
                    }
                    else{
                        vjog.x+=0.5;
                        voutro.x-=0.5;
                    }
                }
                else{
                    if(outro->getPos().y<getPos().y){
                        vjog.y-=0.5;
                        voutro.y+=0.5;
                    }
                    else{
                        vjog.y+=0.5;
                        voutro.y-=0.5;
                    } 
                }
                setVel(voutro);
                outro->setVel(vjog);
            }
            else if(outro->getId()=='a'){//inimigo

            }
        }
        
        void Inimigo::setJog(Jogador* JOG){
            jog=JOG;
        }
    };
};