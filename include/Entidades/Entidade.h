#pragma once

//Cabeçalhos Padrões:
#include<SFML/Graphics.hpp>
using namespace sf;

//Cabeçalhos Próprios:
#include"../Ente.h"

namespace Entidades{
    class Entidade: public Ente{
        protected:
            int x, y;
            Vector2f tam, pos;
            Texture text;
            Sprite sprt;
        public:
            Entidade(int X=0, int Y=0, Vector2f TAM=Vector2f(0.f, 0.f), Vector2f POS=Vector2f(0.f, 0.f), Texture TEXT=Texture(), Sprite SPRT=Sprite(), int ID=0);
            ~Entidade();
            void setTam(Vector2f TAM);
            void setPos(Vector2f POS);
            Vector2f getTam() const;
            Vector2f getPos() const;
            Sprite getSprite() const;
    };
}using namespace Entidades;