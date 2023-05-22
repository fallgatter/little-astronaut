#pragma once
#include<SFML/Graphics.hpp>
#include"../include/Gerenciadores/Eventos.h"
#include"../include/Gerenciadores/Grafico.h"

class Principal{
    private:
        sf::RenderWindow janela;
        Gerenciadores::Eventos* Ge;
        Gerenciadores::Grafico Ga;
    public:
        Principal();
        ~Principal();
        void executar();
};