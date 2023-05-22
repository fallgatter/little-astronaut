#pragma once
#include<SFML/Graphics.hpp>
#include"../include/Gerenciadores/Eventos.h"
#include"../include/Gerenciadores/Grafico.h"
#include"../include/Entidades/Jogador.h"

class Principal{
    private:
        sf::RenderWindow janela;
        Gerenciadores::Eventos* Ge;
        Gerenciadores::Grafico Ga;
        Entidades::Jogador jogador;
    public:
        Principal();
        ~Principal();
        void executar();
};