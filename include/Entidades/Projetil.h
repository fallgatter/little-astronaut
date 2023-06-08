#pragma once

//Cabeçalhos Próprios:
#include"Entidade.h"

namespace Entidades{
    class Projetil: public Entidade{
        protected:
            float coef;
        public:
            Projetil(float COEF=0);
            ~Projetil();
            void lancar(Vector2f VEL, Vector2f POS);
            void mover_se();
            void colidir(Entidade* outro, Vector2f ds);
    };
}using namespace Entidades;