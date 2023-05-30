#pragma once

//Cabeçalhos Padrões:
#include<SFML/Graphics.hpp>
using namespace sf;

//Cabeçalhos Próprios:
#include"../Entidade.h"

namespace Entidades{
    namespace Personagens{
        class Personagem: public Entidade{
            protected:
                float vida, dano;
            public:
                Personagem(float VIDA=0, float DANO=0, Vector2f TAM=Vector2f(0.f, 0.f), Vector2f POS=Vector2f(0.f, 0.f), Vector2f VEL=Vector2f(0.f, 0.f), Vector2f ACEL=Vector2f(0.f, 0.f), Texture TEXT=Texture(), Sprite SPRT=Sprite(), int ID=0);
                ~Personagem();
                void setVida(float VIDA);
                void setDano(float DANO);
                float getVida() const;
                float getDano() const;
                virtual void colidir(Entidade* outro, Vector2f ds){};
        };
    }using namespace Personagens;
}using namespace Entidades;