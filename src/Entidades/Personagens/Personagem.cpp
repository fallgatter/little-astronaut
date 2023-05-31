//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Personagem.h"
//#include "Jogador.h"

namespace Entidades{
    namespace Personagens{
        Personagem::Personagem(float Vida, float Dano, Vector2f Tam, Vector2f Pos, Vector2f Vel, Vector2f Acel, Texture Text, Sprite Sprt, int id): 
            Entidade(Tam, Pos, Vel, Acel, Text, Sprt, id), vida(Vida), dano(Dano)
        {
        }

        Personagem::~Personagem(){
        }
        Personagem::Personagem(Vector2f Pos) {
            Vector2f TAM =(Vector2f(30.f,30.f)), VEL = Vector2f(0.f,0.f), ACEL = Vector2f(0.f,0.f);
            pos = Pos;
            tam = TAM;
            vel = VEL;
            text =Texture();
            sprt = Sprite();
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