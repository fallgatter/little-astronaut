#pragma once

//Cabeçalhos Padrões:
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;

//Cabeçalhos Próprios:
#include"../Entidades/Personagens/Jogador.h"
#include"Gerenciador_Grafico.h"

namespace Gerenciadores{
    class Gerenciador_Eventos{
        private:
            Jogador* jog;
            Gerenciador_Grafico* Ga;

            //Padrão de Projeto Singleton:
            static Gerenciador_Eventos* P;
            Gerenciador_Eventos(Jogador* JOG=NULL);
        public:
            ~Gerenciador_Eventos();
            static Gerenciador_Eventos* Singleton();
            void setJog(Jogador* JOG);
            void executar();
    };
}using namespace Gerenciadores;