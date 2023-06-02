#pragma once
#include<SFML/Graphics.hpp>
#include"../include/Gerenciadores/Eventos.h"
#include"../include/Gerenciadores/Grafico.h"
#include"../include/Entidades/Personagens/Jogador.h"
#include"../include/Entidades/Personagens/Inimigo.h"
#include"../include/Lista/Lista_de_entidades.h"
#include"../include/Gerenciadores/Colisoes.h"
#include"../include/Entidades/Obstaculos/Obstaculo.h"
#include"../include/Fases/Lua.h"

class Principal{
    private:
        sf::RenderWindow janela;
        sf::View *Vw;
        Eventos* Ge;
        Grafico* Ga;
        Jogador* jogador;
        Lista_Entidades ent;
        Colisoes GC;
        Lua moon;
    public:
        Principal();
        ~Principal();
        void executar();
};