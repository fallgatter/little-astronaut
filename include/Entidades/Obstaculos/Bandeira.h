#pragma once

//Cabeçalhos Próprios:
#include"Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        class Bandeira: public Obstaculo{
            private:
                int tipo_text;
                bool p1;//se p1(true), algum jogador terminou a fase
            public:
                Bandeira(Vector2f POS=Vector2f(0.f, 0.f), int TIPO_TEXT=0);
                ~Bandeira();
                void setP1(bool P1);
                bool getP1() const;
                void mover_se();
                void colidir(Entidade* outro, Vector2f ds);
        };
    }using namespace Obstaculos;
}using namespace Entidades;