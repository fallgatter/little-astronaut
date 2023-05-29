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

        void Jogador::colidir(Entidade* outro){
            if(outro->getId()=='o'){//objeto
                
            }
            else if(outro->getId()=='i'){//inimigo
                
                Vector2f vaux = getVel(), vpos;
                vaux.x = -vaux.x/2 + 0.0001;
                vaux.y = -vaux.y/2 + 0.0001;
                setVel(vaux);
                vaux.x = -vaux.x - 0.0001;
                vaux.y = -vaux.y - 0.0001;
                outro->setVel(vaux);
                vpos.x = getPos().x + (getPos().x -  outro->getPos().x)/10; //calculo de knockback
                vpos.y = getPos().y;
                setPos(vpos);
            }
            else if(outro->getId()=='j'){//jogador

            }
            else if(outro->getId()=='p'){//projéti

            }
        }
    };
};