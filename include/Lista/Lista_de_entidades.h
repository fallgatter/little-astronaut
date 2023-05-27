#pragma once

//Standard Libraries:
#include"List.h"

//Game Libraries:
#include"../Entidades/Entidade.h"

namespace Lists{
    class Entity_List{
        public:
            List<Entidade> EL;
            Entity_List() : EL(){}
};

} using namespace Lists;