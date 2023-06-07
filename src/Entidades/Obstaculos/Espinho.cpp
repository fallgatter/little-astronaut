#include"../../../include/Entidades/Obstaculos/ESpinho.h"

namespace Obstaculos{
    Espinho::Espinho(Vector2f Pos, int Na) : Obstaculo(Pos, 0, 'e'), nivel_de_afiacao(rand()%2 + 1){
        text.loadFromFile("assets\\textures\\World\\moon_thorns.png");
        dano = nivel_de_afiacao;
        sprt.setTexture(text);
    }
    Espinho::~Espinho(){}
    void Espinho::mover_se(){
        vel.y -= gravid;
    }
    int Espinho::getAfiacao(){
        return nivel_de_afiacao;
    }
} using namespace Obstaculos;