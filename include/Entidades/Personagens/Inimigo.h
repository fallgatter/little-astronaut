#pragma once

//Cabeçalhos Próprios:
#include"Personagem.h"
#include"Jogador.h"

namespace Entidades{
    namespace Personagens{
        class Inimigo: public Personagem{
            protected:
                static Jogador* jog1;
                static Jogador* jog2;
            public:
                Inimigo(Vector2f POS=Vector2f(0.f, 0.f), int ID='i');
                ~Inimigo();
                static void setJog(Jogador* JOG, int ID);
                virtual void perseguir(Vector2f dist){};
                virtual void mover_se(){};
                void colidir(Entidade* outro, Vector2f ds);
        };
    }using namespace Personagens;
}using namespace Entidades;