#pragma once
#include"../Entidade.h"

namespace Obstaculos{
    class Obstaculo : public Entidade{
        private:
            int tipo_text;
        public:
            Obstaculo(Vector2f POS=Vector2f(0.f, 0.f), int TIPO_TEXT=0);
            ~Obstaculo();
            void colidir(Entidade* outro, Vector2f ds);
            void mover_se();
    };
} using namespace Obstaculos;