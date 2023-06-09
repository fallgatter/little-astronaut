#pragma once

//Cabeçalhos Próprios:
#include"Personagem.h"

namespace Entidades{
    namespace Personagens{
        class Jogador: public Personagem{
            private:
                int energia, pontuacao;
            public:
                Jogador(Vector2f POS=Vector2f(0.f, 0.f), int ID='j');
                ~Jogador();
                void setEnerg(int ENERGIA);
                void setPontuacao(int PONTOS);
                int getEnerg() const;
                int getPontuacao() const;
                void mover_se();
                void colidir(Entidade* outro, Vector2f ds);
        };
    }using namespace Personagens;
}using namespace Entidades;