#pragma once

//Standard Libraries:
#include"List.h"

//Game Libraries:
#include"../Entidades/Entidade.h"

namespace Lists{
    class Lista_Entidades{
        public:
            List<Entidade*> EL;
            Lista_Entidades() : EL(){}
            void incluir(Entidade* ent);
};

} using namespace Lists;