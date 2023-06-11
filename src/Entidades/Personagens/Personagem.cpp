//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Personagem.h"

namespace Entidades{
    namespace Personagens{
        Personagem::Personagem(int VIDAS, int DANO, bool VIVO, Vector2f TAM, Vector2f POS, int ID): 
            Entidade(DANO, VIVO, TAM, POS, ID), vidas(VIDAS)
        {
            
        }

        Personagem::~Personagem(){
            
        }

        void Personagem::setVidas(int VIDAS){
            vidas=VIDAS;
        }
        
        int Personagem::getVidas() const{
            return vidas;
        }

        void Personagem::sofrerDano(int DANO){
            setVidas(getVidas()-DANO);
            if(getVidas() <= 0){
                vivo = false;
            }
        }
        void Personagem::operator--(){
            vidas--;
        }
    };
};