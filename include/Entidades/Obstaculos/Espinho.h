#pragma once

#include"Obstaculo.h"

namespace Obstaculos{
    class Espinho : public Obstaculo{
        private:
            int nivel_de_afiacao;
        public:
            Espinho(Vector2f Pos=Vector2f(0.f, 0.f), int Naf=1);
            ~Espinho();
            void mover_se();
            int getAfiacao();
    };
}using namespace Obstaculos;