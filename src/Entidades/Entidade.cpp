//Cabeçalhos Próprios:
#include"../../include/Entidades/Entidade.h"

namespace Entidades{
    Entidade::Entidade(int X, int Y, Vector2f TAM, Vector2f POS, Texture TEXT, Sprite SPRT, int ID): 
        Ente(ID), x(X), y(Y), tam(TAM), pos(POS), text(TEXT), sprt(SPRT)
    {
        sprt.setTexture(text);
        sprt.setPosition(pos);
        sprt.setScale(tam);
    }

    Entidade::~Entidade(){
    }

    void Entidade::setTam(Vector2f TAM)
    {
        tam=TAM;
    }

    void Entidade::setPos(Vector2f POS){
        pos=POS;
        sprt.setPosition(pos);
    }

    Vector2f Entidade::getTam() const{
        return tam;
    }

    Vector2f Entidade::getPos() const{
        return pos;
    }

    Sprite Entidade::getSprite() const{
        return sprt;
    }
};