#pragma once

//Cabeçalhos Próprios:
#include"Lista.h"
#include"../Entidades/Entidade.h"

namespace Listas{
    class Lista_Entidades{
        public:
            Lista<Entidade*> EL;
            Lista_Entidades(): EL(){}
            ~Lista_Entidades(){
            }
            void incluir(Entidade* ent){
                EL.push(ent);
            }
            Entidade* operator[](int idx){
                return EL[idx];
            }
            int tamanho(){
                return EL.get_size();
            }
    };
} using namespace Listas;