//Cabeçalhos Próprios:
#include"../include/Ente.h"

Ente::Ente(int ID): 
    id(ID), pga(pga->Singleton())
{
    
}

Ente::~Ente(){
    pga=NULL;
}

void Ente::setId(int ID){
    id = ID;
}

int Ente::getId() const{
    return id;
}