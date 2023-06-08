//Cabeçalhos Próprios:
#include"../../../include/Entidades/Obstaculos/Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        Obstaculo::Obstaculo(Vector2f POS, bool RUGOSO, int ID): 
            Entidade(0, true, Vector2f(48.f, 48.f), POS, ID), rugoso(RUGOSO)
        {

        }

        Obstaculo::~Obstaculo(){

        }

        bool Obstaculo::getRugoso() const{
            return rugoso;
        }
    };
};