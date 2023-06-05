#pragma once

//Cabeçalhos Próprios:
#include"../Entidade.h"

namespace Entidades{
    namespace Personagens{
        class Personagem: public Entidade{
            protected:
                float vida, dano;
            public:
                Personagem(float VIDA=0, float DANO=0, Vector2f TAM=Vector2f(0.f,0.f), Vector2f POS=Vector2f(0.f, 0.f), int ID=0);
                ~Personagem();
                void setVida(float VIDA);
                void setDano(float DANO);
                float getVida() const;
                float getDano() const;
                virtual void mover_se(){};
                virtual void colidir(Entidade* outro, Vector2f ds){};
        };
    }using namespace Personagens;
}using namespace Entidades;