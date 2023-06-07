//Cabeçalhos Próprios:
#include"../../include/Entidades/Projetil.h"
#include"../../include/Entidades/Personagens/Personagem.h"

namespace Entidades{
    Projetil::Projetil(): 
        Entidade(Vector2f(24.f, 4.f), Vector2f(0.f, 0.f), 'p'), dano(1)
    {
        text.loadFromFile("assets\\textures\\Others\\laser.png");
        sprt.setTexture(text);
        sprt.setPosition(pos);
    }

    Projetil::~Projetil(){
    }

    void Projetil::setDano(float DANO){
        dano=DANO;
    }

    float Projetil::getDano() const{
        return dano;
    }

    void Projetil::lancar(Vector2f VEL, Vector2f POS){
        setVel(VEL);
        setPos(POS);
    }

    void Projetil::mover_se(){
        vel.y -= 0.1;
        if(vel.x < 0){
            vel.x -= 0.04;
        }
        else if(vel.x > 0){
            vel.x += 0.04;
        }
    }

    void Projetil::colidir(Entidade* outro, Vector2f ds){
        if(outro->getId()=='j'){
            static_cast<Personagem*>(outro)->sofrerDano();
            setPos(Vector2f(0.f, 0.f));
        }
        else if(outro->getId()=='b')
            setPos(Vector2f(0.f, 0.f));
    }
};