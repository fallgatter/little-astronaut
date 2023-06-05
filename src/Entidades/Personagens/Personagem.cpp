//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Personagem.h"

namespace Entidades{
    namespace Personagens{
        Personagem::Personagem(float VIDA, float DANO, Vector2f TAM, Vector2f POS, int ID): 
            Entidade(TAM, POS, ID), vida(VIDA), dano(DANO) , vivo(true)
        {
            
        }

        Personagem::~Personagem(){
        }
        
        void Personagem::setVida(float VIDA){
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