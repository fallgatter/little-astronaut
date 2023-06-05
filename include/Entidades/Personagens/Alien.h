#pragma once

//Cabeçalhos Próprios:
#include"Inimigo.h"

namespace Entidades{
    namespace Personagens{
        class Alien: public Inimigo{
            private:
                int tipo_text;
            public:
                Alien(Vector2f POS=Vector2f(0.f, 0.f), int TIPO_TEXT=0);
                ~Alien();
                void atirar();
                void perseguir(Vector2f dist);
                void mover_se();
        };
    }using namespace Personagens;
}using namespace Entidades;