#include"../../include/Entidades/Inimigo.h"


namespace Entidades{

    Inimigos::Inimigos(float VIDA, float DANO, Vector2f VEL, int X, int Y, Vector2f TAM, Vector2f POS, Texture TEXT, Sprite SPRT, int ID): 
        Entidade(X, Y, TAM, POS, TEXT, SPRT, ID), vida(VIDA), dano(DANO), vel(VEL)
    {
    }

    Inimigos::~Inimigos(){
    }

    void Inimigos::setVida(float VIDA)
    {
        vida=VIDA;
    }

    void Inimigos::setDano(float DANO){
        dano=DANO;
    }

    void Inimigos::setVel(Vector2f VEL){
        vel=VEL;
    }

    float Inimigos::getVida() const{
        return vida;
    }

    float Inimigos::getDano() const{
        return dano;
    }

    const Vector2f Inimigos::getVel() const{
        return vel;
    }
};