#pragma once

//Cabeçalhos Próprios:
#include"Personagem.h"

namespace Entidades{
    namespace Personagens{
        class Inimigo: public Personagem{
            private:

            public:
                Inimigo(Vector2f POS=Vector2f(0.f, 0.f));
                ~Inimigo();
                void colidir(Entidade* outro, Vector2f ds);
        };
    }using namespace Personagens;
}using namespace Entidades;