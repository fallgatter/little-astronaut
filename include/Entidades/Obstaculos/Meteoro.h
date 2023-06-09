#pragma once

//Cabeçalhos Próprios:
#include"Obstaculo.h"
#include"../Personagens/Jogador.h"

namespace Entidades{
    namespace Obstaculos{
        class Meteoro: public Obstaculo{
            private:
                static Jogador* jog1;
                static Jogador* jog2;
                float coef_vel;
                bool caindo;
            public:
                Meteoro(Vector2f POS=Vector2f(0.f, 0.f), float COEF_VEL=1);
                ~Meteoro();
                static void setJog(Jogador* JOG, int ID);
                void cair();
                void mover_se();
                void colidir(Entidade* outro, Vector2f ds);
        };
    }using namespace Obstaculos;
}using namespace Entidades;