#pragma once

//Cabeçalhos Próprios:
#include"Inimigo.h"

namespace Entidades{
    namespace Personagens{
        class OVNI: public Inimigo{
            private:
                int coef_vel;
            public:
                OVNI(Vector2f POS=Vector2f(0.f, 0.f), int COEF_VEL=0);
                ~OVNI();
                void perseguir(Vector2f dist);
                void mover_se();
        };
    }using namespace Personagens;
}using namespace Entidades;