#pragma once

//Cabeçalhos Próprios:
#include"Personagem.h"

namespace Entidades{
    namespace Personagens{
        class Jogador: public Personagem{
            private:
                int energia;
            public:
                Jogador(Vector2f POS=Vector2f(0.f, 0.f));
                ~Jogador();
                void interacao(Keyboard* tecla);
                void colidir(Entidade* outro, Vector2f ds);
        };
    }using namespace Personagens;
}using namespace Entidades;