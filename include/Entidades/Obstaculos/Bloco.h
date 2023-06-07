#pragma once

//Cabeçalhos Próprios:
#include"Obstaculo.h"

namespace Obstaculos{
    class Bloco: public Obstaculo{
        private:
            int tipo_text;
        public:
            Bloco(Vector2f POS=Vector2f(0.f, 0.f), int TIPO_TEXT=0);
            ~Bloco();
            void mover_se();
            int gettipo_text();
    };
}using namespace Obstaculos;