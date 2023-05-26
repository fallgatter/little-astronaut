#pragma once

//Cabeçalhos Próprios:
#include"Entidade.h"

namespace Entidades{
    class Jogador : public Entidade{
        private:
            float vida, dano;
            Vector2f vel;
        public:
            Jogador(float VIDA=0, float DANO=0, Vector2f VEL=Vector2f(0.f, 0.f), int X=0, int Y=0, Vector2f TAM=Vector2f(0.f, 0.f), Vector2f POS=Vector2f(0.f, 0.f), Texture TEXT=Texture(), Sprite SPRT=Sprite(), int ID=0);
            ~Jogador();
            void setVida(float VIDA);
            void setDano(float DANO);
            void setVel(Vector2f VEL);
            float getVida() const;
            float getDano() const;
            const Vector2f getVel() const;
            void interacao(Keyboard* tecla);
    };
}using namespace Entidades;