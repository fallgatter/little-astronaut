#pragma once

//Cabeçalhos Próprios:
#include"Fase.h"

namespace Fases{
    class Marte: public Fase{
        private:
            Gato* chefao;
        public:
            Marte(int ID='M');
            ~Marte();
            void criarMapa();
            bool terminada();
            void terminar();
    };
}using namespace Fases;