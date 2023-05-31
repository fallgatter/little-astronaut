#pragma once
#include"../Ente.h"
#include"../Lista/Lista_de_entidades.h"
#include"../Gerenciadores/Colisoes.h"
#include"../Gerenciadores/Grafico.h"

namespace Fases{
    class Fase: public Ente{
        protected:
            Lista_Entidades LE;
        public:
            Fase(int ID=0);
            ~Fase();
            void criarEntidade(char letra='0', const Vector2f POS=Vector2f(0.f, 0.f));
            void executar();
    };
}using namespace Fases;
