//Game Libraries:
#include"../include/Ente.h"

Ente::Ente(int ID){
    id = ID;
}

Ente::~Ente(){
}

int Ente::getId() const {
    return id;
}