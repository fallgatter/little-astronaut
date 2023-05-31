#pragma once
#include"Fase.h"

namespace Fases{
    class Lua: public Fase{
        public:
            Lua(int ID=0);
            ~Lua();
            void criarMapa();
    };
}using namespace Fases;