#pragma once

//Cabeçalhos Próprios:
#include"../Listas/Lista_Entidades.h"
#include"../Entidades/Personagens/Personagem.h"
//Cabeçalhos Padrões:
#include<math.h>

namespace Gerenciadores{
    class Gerenciador_Colisoes{
        private:
            Lista_Entidades personagens;
            Lista_Entidades obstaculos;
        public:
            Gerenciador_Colisoes();
            ~Gerenciador_Colisoes();
            void gerenciar();
            void setList(Lista_Entidades listAux);
    };
}using namespace Gerenciadores; 