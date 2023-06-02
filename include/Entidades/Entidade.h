#pragma once

//Cabeçalhos Padrões:
#include<SFML/Graphics.hpp>
using namespace sf;

//Cabeçalhos Próprios:
#include"../Ente.h"

namespace Entidades{
    class Entidade: public Ente{
        protected:
            Vector2f tam, pos, vel, acel;
            Texture text;
            Sprite sprt;
        public:
            Entidade(Vector2f TAM=Vector2f(0.f, 0.f), Vector2f POS=Vector2f(0.f, 0.f), int ID=0);
            ~Entidade();
            void setSprite(Sprite sprtaux);
            void setTam(Vector2f TAM);
            void setPos(Vector2f POS);
            void setVel(Vector2f VEL);
            void setAcel(Vector2f ACEL);
            Sprite getSprite() const;
            Vector2f getTam() const;
            Vector2f getPos() const;
            const Vector2f getVel() const;
            const Vector2f getAcel() const;
            void desacelerar();
            void gravidade();
            void mover_se();
            virtual void colidir(Entidade* outro, Vector2f ds)=0;
            void setscale(Vector2f scale);
    };
}using namespace Entidades;