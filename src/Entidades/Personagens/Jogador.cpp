//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Jogador.h"

namespace Entidades{
    namespace Personagens{
        Jogador::Jogador(float VIDA, float DANO, Vector2f TAM, Vector2f POS, Vector2f VEL, Vector2f ACEL, Texture TEXT, Sprite SPRT, int ID): 
            Personagem(VIDA, DANO, TAM, POS, VEL, ACEL, TEXT, SPRT, ID)
        {
        }

        Jogador::~Jogador(){
        }
        Jogador::Jogador(Vector2f POs) : Personagem(POs){
            Texture txt;
            Sprite spr;
            txt.loadFromFile("assets\\textures\\Player\\default.png");
            spr.setTexture(txt);
            setSprite(spr);
            id = 'j';
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
            if(outro->getId()=='o'){//objeto
                
            }
            else if(outro->getId()=='i'){//inimigo
                Vector2f vjog = outro->getVel(), voutro=getVel(), posAux=getPos(), posAux_outro=outro->getPos();
                /*vjog.x = -vjog.x/2 + 0.0001;
                vjog.y = -vjog.y/2 + 0.0001;
                setVel(vjog);
                vjog.x = -vjog.x - 0.0001;
                vjog.y = -vjog.y - 0.0001;
                outro->setVel(vjog);*/

                if(ds.x>ds.y){
                    if(outro->getPos().x<getPos().x){
                        vjog.x+=0.0001;
                        voutro.x-=0.0001;
                    }
                    else{
                        vjog.x-=0.0001;
                        voutro.x+=0.0001;
                    }
                }
                else{
                    if(outro->getPos().y<getPos().y){
                        vjog.y+=0.0001;
                        voutro.y-=0.0001;
                    }
                    else{
                        vjog.y-=0.0001;
                        voutro.y+=0.0001;
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