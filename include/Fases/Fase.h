#pragma once
#include"../Ente.h"
#include"../Lista/Lista_de_entidades.h"
#include"../Gerenciadores/Colisoes.h"
#include"../Gerenciadores/Grafico.h"
#include"../Entidades/Personagens/Inimigo.h"
#include"../Entidades/Personagens/Jogador.h"
#include"../Entidades/Personagens/Personagem.h"


namespace Fases{
    class Fase: public Ente{
        protected:
            Lista_Entidades LE;
            Colisoes* Pco;
            RenderWindow* janela;
        public:
            Fase(int ID=0);
            ~Fase();
            void criarEntidade(int letra='0', const Vector2f POS=Vector2f(0.f, 0.f));
            void executar();
            void setGrafico(Grafico* Pg);
            void setColisoes(Colisoes* Pc);
            void setJanelas(RenderWindow* JNL);
    };
}using namespace Fases;
