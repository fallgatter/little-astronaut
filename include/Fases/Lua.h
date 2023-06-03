#pragma once

//Cabeçalhos Próprios:
#include"Fase.h"

namespace Fases{
    class Lua: public Fase{
        public:
            Lua(int ID='L');
            ~Lua();
            void criarMapa();
    };
}using namespace Fases;