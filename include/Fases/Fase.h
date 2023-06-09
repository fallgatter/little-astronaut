#pragma once

//Cabeçalhos Próprios:
#include"../Ente.h"
#include"../Listas/Lista_Entidades.h"
#include"../Gerenciadores/Gerenciador_Colisoes.h"
#include"../Gerenciadores/Gerenciador_Eventos.h"
#include"../Gerenciadores/Gerenciador_Grafico.h"
#include"../Entidades/Personagens/Jogador.h"
#include"../Entidades/Personagens/Alien.h"
#include"../Entidades/Personagens/OVNI.h"
#include"../Entidades/Personagens/Gato.h"
#include"../Entidades/Obstaculos/Bloco.h"
#include"../Entidades/Obstaculos/Espinho.h"
#include"../Entidades/Obstaculos/Meteoro.h"
#include"../Entidades/Obstaculos/Bandeira.h"
#include"../Menu/Game_Over.h"


namespace Fases{
    class Fase: public Ente{
        protected:
            Lista_Entidades LE;
            Gerenciador_Colisoes Gc;
            Gerenciador_Eventos* Ge;
            static Jogador* jog1;
            static Jogador* jog2;
            const float gravidade;
            int pontuacao, quant_jogadores;
            Game_Over Go;
        public:
            Fase(int ID='F', const float GRAVIDADE=0);
            virtual ~Fase();
            void setPontuacao(int PONTOS);
            int getPontuacao() const;
            void criarEntidade(int letra='0', Vector2f POS=Vector2f(0.f, 0.f), int tipo_text=0);
            virtual bool terminada(){return false;}
            virtual void terminar(){};
            void executar();
            void setquantJog(int quant);
    };
}using namespace Fases;
