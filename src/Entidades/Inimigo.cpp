#include"../../include/Entidades/Inimigo.h"


namespace Entidades{

    Inimigo::Inimigo(float VIDA, float DANO, Vector2f VEL, int X, int Y, Vector2f TAM, Vector2f POS, Texture TEXT, Sprite SPRT, int ID): 
        Entidade(X, Y, TAM, POS, TEXT, SPRT, ID), vida(VIDA), dano(DANO), vel(VEL)
    {
    }

    Inimigo::~Inimigo(){
    }

    void Inimigo::setVida(float VIDA)
    {
        vida=VIDA;
    }

    void Inimigo::setDano(float DANO){
        dano=DANO;
    }

    void Inimigo::setVel(Vector2f VEL){
        vel=VEL;
    }

    float Inimigo::getVida() const{
        return vida;
    }

    float Inimigo::getDano() const{
        return dano;
    }

    const Vector2f Inimigo::getVel() const{
        return vel;
    }
};