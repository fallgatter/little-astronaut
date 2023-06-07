//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Inimigo.h"

namespace Entidades{
    namespace Personagens{
        Jogador* Inimigo::jog(NULL);
        
        Inimigo::Inimigo(Vector2f POS, int ID): 
            Personagem(5, 1, true, Vector2f(38.f, 48.f), POS, ID)
        {
            
        }
        
        Inimigo::~Inimigo(){
        }

        void Inimigo::setJog(Jogador* JOG){
            jog=JOG;
        }

        void Inimigo::colidir(Entidade* outro, Vector2f ds){
            if(outro->getId()=='b'){//objeto
                Vector2f posAux=getPos();  
                if(ds.x>ds.y){
                    if(getPos().x<outro->getPos().x)//colisão em x
                        posAux.x+=ds.x;
                    else
                        posAux.x-=ds.x;
                    setVel(Vector2f(0.f, getVel().y));
                }
                else{
                    if(getPos().y<outro->getPos().y)
                        posAux.y+=ds.y;
                    else
                        posAux.y-=ds.y;
                    setVel(Vector2f(getVel().x, 0.f));
                }
                setPos(posAux);
            }
            else if(outro->getId()=='j'){//jogador
                Vector2f vjog = getVel(), voutro=outro->getVel();
                if(ds.x>ds.y){
                    if(outro->getPos().x<getPos().x){
                        vjog.x-=1.5;
                        voutro.x+=1.5;
                        static_cast<Personagem*>(outro)->sofrerDano(getDano());
                    }
                    else{
                        vjog.x+=1.5;
                        voutro.x-=1.5;
                        static_cast<Personagem*>(outro)->sofrerDano(getDano());
                    }
                }
                else{
                    if(outro->getPos().y<getPos().y){
                        vjog.y-=1.5;
                        voutro.y+=1.5;
                        static_cast<Personagem*>(outro)->sofrerDano(getDano());
                    }
                    else{
                        vjog.y+=1.5;
                        voutro.y-=1.5;
                        sofrerDano(outro->getDano());
                    } 
                }
                setVel(voutro);
                outro->setVel(vjog);
            }
            else if(outro->getId()=='a' || outro->getId()=='v' || outro->getId()=='p'){//inimigo

            }
        }
    };
};