//Cabeçalhos Próprios:
#include"../../include/Entidades/Entidade.h"

namespace Entidades{
    Entidade::Entidade(Vector2f TAM, Vector2f POS, Vector2f VEL, Vector2f ACEL, Texture TEXT, Sprite SPRT, int ID): 
        Ente(ID), tam(TAM), pos(POS), text(TEXT), sprt(SPRT), vel(VEL), acel(ACEL)
    {
        sprt.setTexture(text);
        //sprt.setPosition(pos);
        //sprt.setScale(tam);
    }

    Entidade::~Entidade(){
    }

    void Entidade::setSprite(Sprite sprtaux){
        sprt = sprtaux;
        sprt.setTextureRect(IntRect(0,0,16,16));
        sprt.setScale(Vector2f(3.0f,3.0f));
    }

    void Entidade::setTam(Vector2f TAM)
    {
        tam=TAM;
    }

    void Entidade::setPos(Vector2f POS){
        pos=POS;
        sprt.setPosition(pos);
    }

    void Entidade::setVel(Vector2f VEL){
        vel=VEL;
    }

    void Entidade::setAcel(Vector2f ACEL){
        acel=ACEL;
    }

    Vector2f Entidade::getTam() const{
        return tam;
    }

    Vector2f Entidade::getPos() const{
        return pos;
    }

    const Vector2f Entidade::getVel() const{
        return vel;
    }

    const Vector2f Entidade::getAcel() const{
        return acel;
    }

    Sprite Entidade::getSprite() const{
        return sprt;
    }
    
    void Entidade::desacelerar(){
        if(vel.x != 0){
            if(vel.x < 0){
                vel.x += 0.00001;
            }
            else{
                vel.x -= 0.00001;
            }
        }
        if(pos.y >= 400){
            if(vel.y>0)
                vel.y = 0;
        }
        else{
            gravidade();
        }
        printf("%f\n",pos.y);
    }
    void Entidade::gravidade(){
        vel.y += 0.00001;
    }
    void Entidade::mover_se(){
        pos.x += vel.x;
        pos.y += vel.y;
        setPos(pos);
    }
    void Entidade::setscale(Vector2f SCL){
        sprt.setScale(SCL);
    }
};