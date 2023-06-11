//Cabeçalhos Próprios:
#include"../../include/Entidades/Entidade.h"

namespace Entidades{
    float Entidade::gravid = 0.1;

    Entidade::Entidade(int DANO, bool VIVO, Vector2f TAM, Vector2f POS, int ID): 
        Ente(ID), dano(DANO), vivo(VIVO), tam(TAM), pos(POS), vel(Vector2f(0.f, 0.f))
    {

    }

    Entidade::~Entidade(){
        
    }

    void Entidade::setSprite(Sprite SPRT){
        sprt = SPRT;
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

    void Entidade::setGravidade(float g){
        gravid = g;
    }

    const Sprite Entidade::getSprite() const{
        return sprt;
    }

    const Vector2f Entidade::getTam() const{
        return tam;
    }

    const Vector2f Entidade::getPos() const{
        return pos;
    }

    Vector2f Entidade::getVel() const{
        return vel;
    }

    const int Entidade::getDano() const{
        return dano;
    }

    const bool Entidade::getVivo() const{
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
        Vector2f vel_max=Vector2f(0.f, 0.f);

        if(id == 'j' || id=='g')
            vel_max = Vector2f(3.f,3.f);
        else if(id == 'p')
            vel_max = Vector2f(3.5f,3.5f);
        else if(id == 'm')
            vel_max = Vector2f(10.f,10.f);
        else if(id == 'a' || id == 'v')
            vel_max = Vector2f(2.5f,2.5f);
        else if(id == 'c')
            vel_max = Vector2f(1.5f,1.5f);
        
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
};

