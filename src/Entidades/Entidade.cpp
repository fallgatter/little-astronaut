//Cabeçalhos Próprios:
#include"../../include/Entidades/Entidade.h"

namespace Entidades{
    Entidade::Entidade(Vector2f TAM, Vector2f POS, int ID): 
        Ente(ID), tam(TAM), pos(POS), vel(Vector2f(0.f, 0.f)), acel(Vector2f(0.f, 0.f))
    {
        
    }

    Entidade::~Entidade(){
        
    }

    void Entidade::setSprite(Sprite sprtaux){
        sprt = sprtaux;
        sprt.setTextureRect(IntRect(0,0,16,16));
        sprt.setScale(Vector2f(3.0f,3.0f));
        sprt.setPosition(pos);
    }

    void Entidade::setTam(Vector2f TAM){
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

    void Entidade::setscale(Vector2f SCL){
        sprt.setScale(SCL);
    }

    Vector2f Entidade::getTam() const{
        return tam;
    }

    Vector2f Entidade::getPos() const{
        return pos;
    }

    Vector2f Entidade::getVel() const{
        return vel;
    }

    Vector2f Entidade::getAcel() const{
        return acel;
    }

    Sprite Entidade::getSprite() const{
        return sprt;
    }
    
    void Entidade::desacelerar(){
        if(vel.x != 0){
            if(vel.x < 0){
                vel.x += 0.04;
            }
            else{
                vel.x -= 0.04;
            }
        }
        /*if(pos.y >= 400){
            if(vel.y>0)
                vel.y = 0;
        }
        else{*/
            gravidade();
        //}
        //printf("%f\n",pos.y);
    }

    void Entidade::gravidade(){
        if(id != 'o')
            vel.y += 0.1;
    }
    void Entidade::confere_vel(){
        Vector2f Vel_Max;
        if(id == 'b'){
            setVel(Vector2f(0.f,0.f));
        }
        else if(id == 'j' || id == 'i'){
            if(id == 'j')
                Vel_Max = Vector2f(3.f,3.f);
            else 
                Vel_Max = Vector2f(2.5f,2.5f);
            
            if(vel.x > Vel_Max.x)
                vel.x = Vel_Max.x;
            if(vel.y > Vel_Max.y)
                 vel.y = Vel_Max.y;
             if(vel.x < -Vel_Max.x)
                 vel.x = -Vel_Max.x;
             if(vel.y < -Vel_Max.y)
                 vel.y = -Vel_Max.y;
        }
    }
    void Entidade::mover_se(){
        confere_vel();
        desacelerar();
        
        if(id != 'b'){
            pos.x += vel.x;
            pos.y += vel.y;
            setPos(pos);
        }
        if(id == 'o')
            cout<<"yeah"<<endl;
    }
};