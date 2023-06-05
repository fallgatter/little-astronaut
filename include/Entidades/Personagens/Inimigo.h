#pragma once

//Cabeçalhos Próprios:
#include"Personagem.h"
#include"Jogador.h"

namespace Entidades{
    namespace Personagens{
        class Inimigo: public Personagem{
            protected:
                static Jogador* jog;
            public:
                Inimigo(Vector2f POS=Vector2f(0.f, 0.f), int ID='i');
                ~Inimigo();
                static void setJog(Jogador* JOG);
                virtual void perseguir(){};
                virtual void mover_se(){};
                void colidir(Entidade* outro, Vector2f ds);
        };
    }using namespace Personagens;
}using namespace Entidades;