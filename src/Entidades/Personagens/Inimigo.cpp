//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Inimigo.h"

namespace Entidades{
    namespace Personagens{
        Jogador* Inimigo::jog1(NULL);
        Jogador* Inimigo::jog2(NULL);
        
        Inimigo::Inimigo(Vector2f POS, int ID): 
            Personagem(5, 1, true, Vector2f(38.f, 48.f), POS, ID)
        {
            
        }
        
        Inimigo::~Inimigo(){
        }

        void Inimigo::setJog(Jogador* JOG, int ID){
            if(JOG!=NULL){
                if(ID=='j')//Jogador 1
                    jog1=JOG;
                else if(ID=='g')//Jogador 2
                    jog2=JOG;
            }
        }

        void Inimigo::colidir(Entidade* outro, Vector2f ds){
            if(outro!=NULL){
                if(outro->getId()=='b'){//bloco
                    Vector2f posAux=getPos();  
                    if(ds.x>ds.y){//colisão em x
                        if(getPos().x<outro->getPos().x)
                            posAux.x+=ds.x;
                        else
                            posAux.x-=ds.x;
                        setVel(Vector2f(0.f, getVel().y));
                    }
                    else{//colisão em y
                        if(getPos().y<outro->getPos().y)
                            posAux.y+=ds.y;
                        else
                            posAux.y-=ds.y;
                        setVel(Vector2f(getVel().x, 0.f));
                    }
                    setPos(posAux);
                }
                else if(outro->getId()=='j' || outro->getId()=='g'){//jogadores
                    Vector2f vjog = getVel(), voutro=outro->getVel();
                    if(ds.x>ds.y){//colisão em x
                        if(outro->getPos().x<getPos().x){
                            vjog.x-=1.5;
                            voutro.x+=1.5;
                            static_cast<Personagem*>(outro)->operator--();
                        }
                        else{
                            vjog.x+=1.5;
                            voutro.x-=1.5;
                            static_cast<Personagem*>(outro)->operator--();
                        }
                    }
                    else{//colisão em y
                        if(outro->getPos().y<getPos().y){
                            vjog.y-=1.5;
                            voutro.y+=1.5;
                            static_cast<Personagem*>(outro)->operator--();
                        }
                        else{
                            vjog.y+=1.5;
                            voutro.y-=1.5;
                            sofrerDano(outro->getDano());
                        } 
                    }
                    setVel(voutro);
                    outro->setVel(vjog);
                    if(!getVivo() && getId()=='c')//neutralizou o chefao (gato)
                        static_cast<Jogador*>(outro)->setPontuacao(1000);
                    else if(!getVivo() && getId()!='c')//neutralizou alien/OVNI
                        static_cast<Jogador*>(outro)->setPontuacao(100);
                }
            }
        }
    };
};