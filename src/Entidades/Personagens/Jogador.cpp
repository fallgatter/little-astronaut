//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Jogador.h"
#include"../../../include/Gerenciadores/Gerenciador_Eventos.h"
#include"../../../include/Entidades/Obstaculos/Bloco.h"
#include"../../../include/Entidades/Obstaculos/Espinho.h"
#include"../../../include/Entidades/Obstaculos/Meteoro.h"

namespace Entidades{
    namespace Personagens{
        Jogador::Jogador(Vector2f POS): 
            Personagem(10, 2, true, Vector2f(40.f, 48.f), POS, 'j'), energia(100), pontuacao(0)
        {
            Sprite sprtemp;
            text.loadFromFile("assets\\textures\\Player\\default.png");
            sprtemp.setTexture(text);
            setSprite(sprtemp);
        }

        Jogador::~Jogador(){
        }
        
        void Jogador::setEnerg(int ENERGIA){
            energia=ENERGIA;
        }

        int Jogador::getEnerg() const{
            return energia;
        }

        void Jogador::mover_se(){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && energia){
                vel.y += -0.2;
                energia--;
            }
            if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && energia<100){
                energia++;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                vel.x += 0.2;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                vel.x -= 0.2;
            }
        }

        void Jogador::colidir(Entidade* outro, Vector2f ds){
            if(outro->getId() == 'm'){//meteoro
                sofrerDano(static_cast<Meteoro*>(outro)->getDano());
            }
            else if(outro->getId() == 'e'){//espinho
                if(vel.x != 0) //só sofre dano se estiver se movendo contra o espinho, parado nele não tem problema
                    if(rand()%70 == 1)
                        sofrerDano(static_cast<Espinho*>(outro)->getDano());
                    vel.x*=0.9;
                    vel.y*=0.9;
            }
            else if(outro->getId()=='b'){//bloco
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
                if(static_cast<Bloco*>(outro)->getRugoso())
                    vel.x*=0.5;
                    
                setPos(posAux);
            }
            else if(outro->getId()=='a' || outro->getId()=='v'){//inimigos
                Vector2f vjog = outro->getVel(), voutro=getVel();
                if(ds.x>ds.y){
                    if(outro->getPos().x<getPos().x){
                        vjog.x+=1.5;
                        voutro.x-=1.5;
                        sofrerDano(outro->getDano());
                    }
                    else{
                        vjog.x-=1.5;
                        voutro.x+=1.5;
                        sofrerDano(outro->getDano());
                    }
                }
                else{
                    if(outro->getPos().y<getPos().y){
                        vjog.y+=1.5;
                        voutro.y-=1.5;
                        sofrerDano(outro->getDano());
                    }
                    else{
                        vjog.y-=5;
                        voutro.y+=1.5;
                        static_cast<Personagem*>(outro)->sofrerDano(getDano());
                    } 
                }
                setVel(vjog);
                outro->setVel(voutro);
                cout<<"vidas do jogador: "<<getVidas()<<endl;
                cout<<"vidas do outro: "<<static_cast<Personagem*>(outro)->getVidas()<<endl;
            }
            else if(outro->getId()=='j'){//jogador

            }
            else if(outro->getId()=='p'){//projéti
                sofrerDano(outro->getDano());
                //outro->setPos(Vector2f(0.f,0.f));
                outro->setVivo(false);
                cout<<"vidas do jogador: "<<getVidas()<<endl;
            }
            
        }   
    };
};