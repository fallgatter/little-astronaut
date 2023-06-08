#pragma once

//Cabeçalhos Próprios:
#include"Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        class Espinho: public Obstaculo{
            private:
                int afiacao;
            public:
                Espinho(Vector2f POS=Vector2f(0.f, 0.f), int AFIACAO=1);
                ~Espinho();
                void mover_se();
                void colidir(Entidade* outro, Vector2f ds);
        };
    }using namespace Obstaculos;
}using namespace Entidades;