#pragma once
#include<iostream>
//Cabeçalhos Próprios:
#include"Entidade.h"

namespace Entidades{
    class Inimigos: public Entidade{
        public:
            float vida, dano;
            Vector2f vel;
        private:
            Inimigos(float VIDA=0, float DANO=0, Vector2f VEL=Vector2f(0.f, 0.f), int X=0, int Y=0, Vector2f TAM=Vector2f(0.f, 0.f), Vector2f POS=Vector2f(0.f, 0.f), Texture TEXT=Texture(), Sprite SPRT=Sprite(), int ID=0);
            ~Inimigos();
            void setVida(float VIDA);
            void setDano(float DANO);
            void setVel(Vector2f VEL);
            float getVida() const;
            float getDano() const;
            const Vector2f getVel() const;
        
    };
}using namespace Entidades;