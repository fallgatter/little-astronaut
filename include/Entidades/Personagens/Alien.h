#pragma once

//Cabeçalhos Padrões:
#include <vector>

//Cabeçalhos Próprios:
#include"Inimigo.h"
#include"../Projetil.h"

namespace Entidades{
    namespace Personagens{
        class Alien: public Inimigo{
            private:
                int tipo_text, municao, dt;
                bool recarregando;
                vector<Projetil*> tiros;
            public:
                Alien(Vector2f POS=Vector2f(0.f, 0.f), int TIPO_TEXT=0);
                ~Alien();
                vector<Projetil*> *getTiros();
                void atirar(Vector2f dist);
                void perseguir(Vector2f dist);
                void mover_se();
        };
    }using namespace Personagens;
}using namespace Entidades;