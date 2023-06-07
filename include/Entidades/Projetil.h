#pragma once

//Cabeçalhos Próprios:
#include"Entidade.h"

namespace Entidades{
    class Projetil: public Entidade{
        protected:
            float dano;
        public:
            Projetil();
            ~Projetil();
            void setDano(float DANO);
            float getDano() const;
            void lancar(Vector2f VEL, Vector2f POS);
            void mover_se();
            void colidir(Entidade* outro, Vector2f ds);
    };
}using namespace Entidades;