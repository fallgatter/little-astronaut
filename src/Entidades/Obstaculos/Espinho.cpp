#include"../../../include/Entidades/Obstaculos/ESpinho.h"

namespace Obstaculos{
    Espinho::Espinho(Vector2f Pos, int Na) : Obstaculo(Pos, 0, 'e'), nivel_de_afiacao(rand()%4){}
    Espinho::~Espinho(){}
    void Espinho::mover_se(){
        vel.y -= 0.1;
    }
} using namespace Obstaculos;