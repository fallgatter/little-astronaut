//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Jogador.h"

namespace Entidades{
    namespace Personagens{
        Jogador::Jogador(Vector2f POS): 
            Personagem(5.0, 1.0, Vector2f(40.f, 48.f), POS, 'j'), energia(100)
        {
            Sprite sprtemp;
            text.loadFromFile("assets\\textures\\Player\\default.png");
            sprtemp.setTexture(text);
            setSprite(sprtemp);
        }

        Jogador::~Jogador(){
        }
        
        void Jogador::interacao(Keyboard* tecla){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                vel.y += -0.00003;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                vel.x += 0.00002;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                vel.x -= 0.00002;
            }
        }

        void Jogador::colidir(Entidade* outro, Vector2f ds){
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
            else if(outro->getId()=='a'){//inimigo
                Vector2f vjog = outro->getVel(), voutro=getVel();

                if(ds.x>ds.y){
                    if(outro->getPos().x<getPos().x){
                        vjog.x+=0.1;
                        voutro.x-=0.1;
                    }
                    else{
                        vjog.x-=0.1;
                        voutro.x+=0.1;
                    }
                }
                else{
                    if(outro->getPos().y<getPos().y){
                        vjog.y+=0.1;
                        voutro.y-=0.1;
                    }
                    else{
                        vjog.y-=0.1;
                        voutro.y+=0.1;
                    } 
                }
                setVel(vjog);
                outro->setVel(voutro);
            }
            else if(outro->getId()=='j'){//jogador

            }
            else if(outro->getId()=='p'){//projéti

            }
        }
    };
};