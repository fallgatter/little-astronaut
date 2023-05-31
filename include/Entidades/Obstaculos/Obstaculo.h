#pragma once
#include"../Entidade.h"

namespace Obstaculos{
    class Obstaculo : public Entidade{
        public:
            Obstaculo(Vector2f TAM=Vector2f(0.f, 0.f), Vector2f POS=Vector2f(0.f, 0.f), Vector2f VEL=Vector2f(0.f, 0.f), Vector2f ACEL=Vector2f(0.f, 0.f), Texture TEXT=Texture(), Sprite SPRT=Sprite(), int ID='o');
            ~Obstaculo();
            Obstaculo(Vector2f POs);
            void colidir(Entidade* outro, Vector2f ds);
            void mover_se();
    };
} using namespace Obstaculos;