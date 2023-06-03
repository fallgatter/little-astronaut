#pragma once

//Cabeçalhos Padrões:
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;

//Cabeçalhos Próprios:
#include"../Entidades/Personagens/Jogador.h"

namespace Gerenciadores{
    class Gerenciador_Eventos{
        private:
            Jogador* jog;
            Vector2f pos, vel;
            RenderWindow* Pjanela;
        public:
            Gerenciador_Eventos(Jogador* JOG=NULL, Vector2f POS=Vector2f(0.0f, 0.0f), Vector2f VEL=Vector2f(0.0f, 0.0f));
            ~Gerenciador_Eventos();
            void gerenciarInput(Event* evento);
            void setWindow(RenderWindow* wnd);
    };
}using namespace Gerenciadores;