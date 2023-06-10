#pragma once

//Cabeçalhos Próprios:
#include"Fase.h"
#include"Marte.h"

namespace Fases{
    class Lua: public Fase{
        private:
            Bandeira* flag;
        public:
            Lua(int ID='L');
            ~Lua();
            void criarMapa();
            bool terminada();
            void terminar();
    };
}using namespace Fases;