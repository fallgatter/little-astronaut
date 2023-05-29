#pragma once
#include"../Lista/Lista_de_entidades.h"

namespace Gerenciadores{
    class Colisoes{
        private:
            Lista_Entidades LE;
        public:
            Colisoes();
            ~Colisoes();
            void gerenciar();
            void setList(Lista_Entidades* listAux);
    };
}using namespace Gerenciadores; 