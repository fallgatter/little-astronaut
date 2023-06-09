#pragma once

//Cabeçalhos Padrões:
#include <vector>

//Cabeçalhos Próprios:
#include"Inimigo.h"
#include"../Obstaculos/Meteoro.h"

namespace Entidades{
    namespace Personagens{
        class Gato: public Inimigo{
            private:
                int carga, dt;
                bool recarregando;
                vector<Meteoro*> meteoros;
            public:
                Gato(Vector2f POS=Vector2f(0.f, 0.f));
                ~Gato();
                vector<Meteoro*> *getMeteoros();
                void atirar(Vector2f pos_jog);
                void perseguir(Vector2f dist);
                void mover_se();
        };
    }using namespace Personagens;
}using namespace Entidades;