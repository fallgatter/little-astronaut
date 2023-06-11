//Cabeçalhos Próprios:
#include"../../include/Entidades/Projetil.h"
#include"../../include/Entidades/Personagens/Personagem.h"

namespace Entidades{
    Projetil::Projetil(float COEF): 
        Entidade(1, false, Vector2f(24.f, 4.f), Vector2f(-100.f, -100.f), 'p'), coef_dano(1+COEF/10)
    {
        text.loadFromFile("assets\\textures\\Others\\laser.png");
        sprt.setOrigin(Vector2f(0.f, -25.f));
        sprt.setTexture(text);
        sprt.setTextureRect(IntRect(0,0,24,4));
        sprt.setPosition(pos);
    }

    Projetil::~Projetil(){

    }

    float Projetil::getCoef() const{
        return coef_dano;
    }

    void Projetil::lancar(Vector2f VEL, Vector2f POS){
        setVivo(true);
        setVel(VEL);
        setPos(POS);
    }

    void Projetil::mover_se(){
        vel.y -= gravid;
        if(vel.x < 0){
            vel.x -= 0.04;
        }
        else if(vel.x > 0){
            vel.x += 0.04;
        }
    }

    void Projetil::colidir(Entidade* outro, Vector2f ds){
        if(outro!=NULL){
            if(outro->getId()=='j' || outro->getId()=='g'){//jogadores
                static_cast<Personagem*>(outro)->sofrerDano(getDano() * coef_dano);
                setVivo(false);
            }
            else if(outro->getId()=='b')//bloco
                setVivo(false);
        }
    }
};