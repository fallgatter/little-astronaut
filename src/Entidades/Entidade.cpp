//Cabeçalhos Próprios:
#include"../../include/Entidades/Entidade.h"

namespace Entidades{
    Entidade::Entidade(int DANO, bool VIVO, Vector2f TAM, Vector2f POS, int ID): 
        Ente(ID), dano(DANO), vivo(VIVO), tam(TAM), pos(POS), vel(Vector2f(0.f, 0.f))
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

    void Entidade::setScale(Vector2f SCL){
        sprt.setScale(SCL);
    }

    void Entidade::setDano(int DANO){
        dano=DANO;
    }

    void Entidade::setVivo(bool VIVO){
        vivo=VIVO;
    }

    Sprite Entidade::getSprite() const{
        return sprt;
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

    int Entidade::getDano() const{
        return dano;
    }

    bool Entidade::getVivo() const{
        return vivo;
    }
    
    void Entidade::desacelerar(){
        if(vel.x>-0.05 && vel.x<0.05)
            vel.x=0.0;
        else if(vel.x < -0.05)
            vel.x += 0.04;
        else if(vel.x > 0.05)
            vel.x -= 0.04;
    }

    void Entidade::gravidade(){
        vel.y += gravid;
    }
    void Entidade::confere_vel(){
        Vector2f vel_max;

        if(id == 'b')
            vel_max = Vector2f(3.f,3.f);
        if(id == 'j' || id=='g')
            vel_max = Vector2f(3.f,3.f);
        if(id == 'p')
            vel_max = Vector2f(3.5f,3.5f);
        if(id == 'm')
            vel_max = Vector2f(10.f,10.f);
        if(id == 'a' || id == 'v')
            vel_max = Vector2f(2.5f,2.5f);
        
        if(vel.x > vel_max.x)
            vel.x = vel_max.x;
        else if(vel.x < -vel_max.x)
            vel.x = -vel_max.x;
        if(vel.y > vel_max.y)
            vel.y = vel_max.y;
        else if(vel.y < -vel_max.y)
            vel.y = -vel_max.y;
        
    }
    void Entidade::atualizar(){
        confere_vel();
        pga->drawn(getSprite());
        pos.x += vel.x;
        pos.y += vel.y;
        setPos(pos);
        mover_se();
        desacelerar();
        gravidade();
    }
    void Entidade::setGravidade(float g){
        gravid = g;
    }
    float Entidade::gravid = 0.1;
};

