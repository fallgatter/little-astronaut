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
                Personagem(float VIDA=0, float DANO=0, Vector2f Tam=Vector2f(40.f,48.f), Vector2f Pos=Vector2f(0.f, 0.f), Vector2f Vel=Vector2f(0.f, 0.f), Vector2f Acel=Vector2f(0.f, 0.f), Texture Text=Texture(), Sprite Sprt=Sprite(), int Id=0);
                Personagem(Vector2f POS);
                ~Personagem();
                void setVida(float VIDA);
                void setDano(float DANO);
                float getVida() const;
                float getDano() const;
                virtual void colidir(Entidade* outro, Vector2f ds){};
        };
    }using namespace Personagens;
}using namespace Entidades;