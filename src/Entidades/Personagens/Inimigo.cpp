//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Inimigo.h"

namespace Entidades{
    namespace Personagens{
        Inimigo::Inimigo(float VIDA, float DANO, Vector2f TAM, Vector2f POS, Vector2f VEL, Vector2f ACEL, Texture TEXT, Sprite SPRT, int ID): 
            Personagem(VIDA, DANO, TAM, POS, VEL, ACEL, TEXT, SPRT, ID)
        {
        }

        Inimigo::~Inimigo(){
        }
    };
};