//Cabeçalhos Próprios:
#include"../../include/Entidades/Entidade.h"

namespace Entidades{
    Entidade::Entidade(int X, int Y, Vector2f TAM, Vector2f POS, Texture TEXT, Sprite SPRT, int ID): 
        Ente(ID), x(X), y(Y), tam(TAM), pos(POS), text(TEXT), sprt(SPRT), vel_instantanea(Vector2f(0.f,0.f))
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
    void Entidade::setSprite(Sprite sprtaux){
        sprt = sprtaux;
        sprt.setTextureRect(IntRect(0,0,16,16));
        sprt.setScale(Vector2f(3.0f,3.0f));
    }
    void Entidade::desacelerar(){
        if(vel_instantanea.x != 0){
            if(vel_instantanea.x < 0){
                vel_instantanea.x += 0.00001;
            }
            else{
                vel_instantanea.x -= 0.00001;
            }
        }
        if(pos.y >= 400){
            if(vel_instantanea.y>0)
                vel_instantanea.y = 0;
        }
        else{
            gravidade();
        }
        printf("%f\n",pos.y);
    }
    void Entidade::gravidade(){
        vel_instantanea.y += 0.00001;
    }
    void Entidade::mover_se(){
        pos.x += vel_instantanea.x;
        pos.y += vel_instantanea.y;
        setPos(pos);
    }
};