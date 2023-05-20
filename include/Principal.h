#pragma once
#include<SFML/Graphics.hpp>
#include"../include/Gerenciadores/Eventos.h"

class Principal{
    private:
        sf::RenderWindow janela;
        Gerenciadores::Eventos* Ge;
    public:
        Principal();
        ~Principal();
        void executar();
};