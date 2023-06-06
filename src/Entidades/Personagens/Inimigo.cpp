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
                if(pos.y - 2 < outro->getPos().y)  //talvez de merda nesse -2
                    atacar_por_contato();
                //static_cast<Jogador*>(outro)->setVida(-5);
                if(ds.x>ds.y){
                    if(outro->getPos().x<getPos().x){
                        vjog.x-=1;
                        voutro.x+=1;
                    }
                    else{
                        vjog.x+=1;
                        voutro.x-=1;
                    }
                }
                else{
                    if(outro->getPos().y<getPos().y){
                        vjog.y-=1;
                        voutro.y+=1;
                        //vida--;
                    }
                    else{
                        vjog.y+=1;
                        voutro.y-=1;
                    } 
                }
                setVel(voutro);
                outro->setVel(vjog);
            }
            else if(outro->getId()=='a' || outro->getId()=='v'){//inimigo

            }
        }
        void Inimigo::atacar_por_contato(){
            //cout<<jog->getVida()<<endl;
            int Vida= jog->getVida();
            if(Vida < 0)
                jog->setVivo(false);
            Vida--;
            jog->setVida(Vida);
        }
        void Inimigo::setJog(Jogador* JOG){
            jog=JOG;
        }
    };
};