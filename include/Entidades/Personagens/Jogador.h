#pragma once

//Cabeçalhos Próprios:
#include"Personagem.h"

namespace Entidades{
    namespace Personagens{
        class Jogador: public Personagem{
            private:
            
            public:
                Jogador(float VIDA=0, float DANO=0, Vector2f TAM=Vector2f(0.f, 0.f), Vector2f POS=Vector2f(0.f, 0.f), Vector2f VEL=Vector2f(0.f, 0.f), Vector2f ACEL=Vector2f(0.f, 0.f), Texture TEXT=Texture(), Sprite SPRT=Sprite(), int ID=0);
                ~Jogador();
                void interacao(Keyboard* tecla);
        };
    }using namespace Personagens;
}using namespace Entidades;