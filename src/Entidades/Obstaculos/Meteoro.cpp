#include"../../../include/Entidades/Obstaculos/Meteoro.h"
#include"../../../include/Entidades/Personagens/Personagem.h"

#define RAIO 96.0

namespace Entidades{
    namespace Obstaculos{
        Jogador* Meteoro::jog(NULL);
        
        Meteoro::Meteoro(Vector2f POS, float COEF_VEL): 
            Obstaculo(POS, true, 'm'), coef_vel(1+(COEF_VEL/10))
        {
            text.loadFromFile("assets\\textures\\Others\\meteor.png");
            sprt.setTexture(text);
            dano=10;
        }

        Meteoro::~Meteoro(){

        }

        void Meteoro::setJog(Jogador* JOG){
            jog=JOG;
        }

        void Meteoro::cair(){
            cout<<"caindo"<<endl;
            setVel(Vector2f(0.f, 4.f*coef_vel));
        }

        void Meteoro::mover_se(){
            vel.y -= gravid;
            float dist;
            if(jog!=NULL && jog->getVivo()){
                dist=jog->getPos().x-getPos().x;
                if(fabs(dist)<=RAIO)
                    cair();
            }
        }

        void Meteoro::colidir(Entidade* outro, Vector2f ds){
            if(outro->getId() == 'j'){//meteoro
                static_cast<Personagem*>(outro)->sofrerDano(getDano());
                setVivo(false);
            }
            else if(outro->getId()=='b')
                setVivo(false);
        }
    };
};