#pragma once

//Cabeçalhos Próprios:
#include"Fase.h"

namespace Fases{
    class Lua: public Fase{
        private:
            Sprite background;
            Texture text;
        public:
            Lua(int ID='L');
            ~Lua();
            void criarMapa();
    };
}using namespace Fases;