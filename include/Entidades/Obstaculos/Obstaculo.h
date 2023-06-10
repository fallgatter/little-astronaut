#pragma once

//Cabeçalhos Próprios:
#include"../Entidade.h"

namespace Entidades{
    namespace Obstaculos{
        class Obstaculo: public Entidade{
            protected:
                bool rugoso;
            public:
                Obstaculo(Vector2f POS=Vector2f(0.f, 0.f), bool RUGOSO=0, int ID='o');
                virtual ~Obstaculo();
                bool getRugoso() const;
                virtual void mover_se(){};
                virtual void colidir(Entidade* outro, Vector2f ds){};
        };
    }using namespace Obstaculos;
}using namespace Entidades;