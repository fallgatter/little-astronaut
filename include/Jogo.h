#pragma once

//Cabeçalhos Próprios:
#include"../include/Fases/Lua.h"
#include"../include/Fases/Marte.h"

class Jogo{
    private:
        Lua moon;
        Marte mars;
    public:
        Jogo();
        ~Jogo();
        void executar();
};