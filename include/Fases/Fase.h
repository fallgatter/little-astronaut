#pragma once

//Cabeçalhos Próprios:
#include"../Ente.h"
#include"../Listas/Lista_Entidades.h"
#include"../Gerenciadores/Gerenciador_Colisoes.h"
#include"../Gerenciadores/Gerenciador_Eventos.h"
#include"../Gerenciadores/Gerenciador_Grafico.h"
#include"../Entidades/Personagens/Jogador.h"
#include"../Entidades/Personagens/Inimigo.h"
#include"../Entidades/Personagens/Alien.h"
#include"../Entidades/Personagens/OVNI.h"
#include"../Entidades/Obstaculos/Bloco.h"
#include"../Entidades/Obstaculos/Espinho.h"


namespace Fases{
    class Fase: public Ente{
        protected:
            Lista_Entidades LE;
            Gerenciador_Colisoes Gc;
            Gerenciador_Eventos* Ge;
            Jogador* jog;
            float gravidade;
        public:
            Fase(int ID='F');
            ~Fase();
            void criarEntidade(int letra='0', Vector2f POS=Vector2f(0.f, 0.f), int tipo_text=0);
            void executar();
    };
}using namespace Fases;
