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

namespace Fases{
    class Fase: public Ente{
        protected:
            Lista_Entidades LE;
            Gerenciador_Colisoes Pco;
            Gerenciador_Eventos* Ge;
            RenderWindow* janela;
            Jogador* jog;
        public:
            Fase(int ID='F');
            ~Fase();
            void criarEntidade(int letra='0', Vector2f POS=Vector2f(0.f, 0.f), int tipo_text=0);
            void executar();
            void setGrafico(Gerenciador_Grafico* Pg);
            void setColisoes(Gerenciador_Colisoes Pc);
            void setJanelas(RenderWindow* JNL);
    };
}using namespace Fases;
