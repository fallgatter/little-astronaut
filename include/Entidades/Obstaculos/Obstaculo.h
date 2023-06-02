#pragma once
#include"../Entidade.h"

namespace Obstaculos{
    class Obstaculo: public Entidade{
        private:
            bool danoso;
        public:
            Obstaculo(Vector2f POS=Vector2f(0.f, 0.f), bool DANOSO=0, int ID='o');
            ~Obstaculo();
            void colidir(Entidade* outro, Vector2f ds);
    };
}using namespace Obstaculos;