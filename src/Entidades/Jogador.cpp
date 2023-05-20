//Cabeçalhos Próprios:
#include"../../include/Entidades/Jogador.h"
//#include "Jogador.h"

namespace Entidades{
    Jogador::Jogador(float VIDA, float DANO, Vector2f VEL, int X, int Y, Vector2f TAM, Vector2f POS, Texture TEXT, Sprite SPRT, int ID): 
        Entidade(X, Y, TAM, POS, TEXT, SPRT, ID), vida(VIDA), dano(DANO), vel(VEL)
    {
    }

    Jogador::~Jogador(){
    }

    void Jogador::setVida(float VIDA)
    {
        vida=VIDA;
    }

    void Jogador::setDano(float DANO){
        dano=DANO;
    }

    void Jogador::setVel(Vector2f VEL){
        vel=VEL;
    }

    float Jogador::getVida() const{
        return vida;
    }

    float Jogador::getDano() const{
        return dano;
    }

    const Vector2f Jogador::getVel() const{
        return vel;
    }

};