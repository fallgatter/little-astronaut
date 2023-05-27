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
    };
};