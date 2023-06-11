#pragma once

//Cabeçalhos Próprios:
#include"../Entidade.h"

namespace Entidades{
    namespace Personagens{
        class Personagem: public Entidade{
            protected:
                int vidas;
            public:
                Personagem(int VIDAS=0, int DANO=0, bool VIVO=false, Vector2f TAM=Vector2f(0.f,0.f), Vector2f POS=Vector2f(0.f, 0.f), int ID=0);
                virtual ~Personagem();
                void setVidas(int VIDAS);
                int getVidas() const;
                void sofrerDano(int DANO);
                void operator++();
                virtual void mover_se(){};
                virtual void colidir(Entidade* outro, Vector2f ds){};
        };
    }using namespace Personagens;
}using namespace Entidades;