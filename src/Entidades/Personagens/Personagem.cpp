//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Personagem.h"
//#include "Jogador.h"

namespace Entidades{
    namespace Personagens{
        Personagem::Personagem(float VIDA, float DANO, Vector2f TAM, Vector2f POS, Vector2f VEL, Vector2f ACEL, Texture TEXT, Sprite SPRT, int ID): 
            Entidade(TAM, POS, VEL, ACEL, TEXT, SPRT, ID), vida(VIDA), dano(DANO)
        {
        }

        Personagem::~Personagem(){
        }

        void Personagem::setVida(float VIDA)
        {
            vida=VIDA;
        }

        void Personagem::setDano(float DANO){
            dano=DANO;
        }

        float Personagem::getVida() const{
            return vida;
        }

        float Personagem::getDano() const{
            return dano;
        }
    };
};