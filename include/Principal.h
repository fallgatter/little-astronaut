#pragma once

//Cabeçalhos Padrões:
#include<SFML/Graphics.hpp>
using namespace sf;

//Cabeçalhos Próprios:
#include"../include/Gerenciadores/Gerenciador_Eventos.h"
#include"../include/Gerenciadores/Gerenciador_Grafico.h"
#include"../include/Entidades/Personagens/Jogador.h"
#include"../include/Entidades/Personagens/Inimigo.h"
#include"../include/Listas/Lista_Entidades.h"
#include"../include/Gerenciadores/Gerenciador_Colisoes.h"
#include"../include/Entidades/Obstaculos/Obstaculo.h"
#include"../include/Fases/Lua.h"

class Principal{
    private:
        Lua moon;
    public:
        Principal();
        ~Principal();
        void executar();
};