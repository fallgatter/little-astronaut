#pragma once
#include<SFML/Graphics.hpp>
#include"../include/Gerenciadores/Eventos.h"
#include"../include/Gerenciadores/Grafico.h"
#include"../include/Entidades/Personagens/Jogador.h"
#include"../include/Entidades/Personagens/Inimigo.h"
#include"../include/Lista/Lista_de_entidades.h"

class Principal{
    private:
        sf::RenderWindow janela;
        Eventos* Ge;
        Grafico Ga;
        Jogador jogador;
        Entity_List ent;
    public:
        Principal();
        ~Principal();
        void executar();
};