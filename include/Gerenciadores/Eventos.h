#pragma once

//Cabeçalhos Padrões:
#include<SFML/Graphics.hpp>
using namespace sf;

//Cabeçalhos Próprios:
#include"../Entidades/Jogador.h"

namespace Gerenciadores{
    class Eventos{
        private:
            Jogador* jog;
            Vector2f pos, vel;
        public:
            Eventos(Jogador* JOG=NULL, Vector2f POS=Vector2f(0.0f, 0.0f), Vector2f VEL=Vector2f(0.0f, 0.0f));
            ~Eventos();
            void gerenciarInput();
    }
}using namespace Gerenciadores;