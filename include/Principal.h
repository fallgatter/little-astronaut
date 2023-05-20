#pragma once
#include<SFML/Graphics.hpp>

class Principal{
    private:
        sf::RenderWindow janela;
    public:
        Principal();
        ~Principal();
        void executar();
};