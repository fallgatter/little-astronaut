#pragma once

//Cabeçalhos Próprios:
#include"Entidade.h"

namespace Entidades{
    class Projetil: public Entidade{
        private:
            float coef_dano;
        public:
            Projetil(float COEF=0);
            ~Projetil();
            float getCoef() const;
            void lancar(Vector2f VEL, Vector2f POS);
            void mover_se();
            void colidir(Entidade* outro, Vector2f ds);
    };
}using namespace Entidades;