#include"../../../include/Entidades/Obstaculos/Meteoro.h"
#include"../../../include/Entidades/Personagens/Personagem.h"

#define RAIO 96.0

namespace Entidades{
    namespace Obstaculos{
        Jogador* Meteoro::jog1(NULL);
        Jogador* Meteoro::jog2(NULL);
        
        Meteoro::Meteoro(Vector2f POS, float COEF_VEL): 
            Obstaculo(POS, true, 'm'), coef_vel(1+(COEF_VEL/10)), caindo(false)
        {
            text.loadFromFile("assets\\textures\\Others\\meteor.png");
            sprt.setTexture(text);
            dano=10;
        }

        Meteoro::~Meteoro(){

        }

        void Meteoro::setJog(Jogador* JOG, int ID){
            if(JOG!=NULL){
                if(ID=='j')//Jogador 1
                    jog1=JOG;
                else if(ID=='g')//Jogador 2
                    jog2=JOG;
            }
        }

        void Meteoro::cair(){
            setVel(Vector2f(0.f, 4.f*coef_vel));
        }

        void Meteoro::cair(Vector2f pos_jog){
            setPos(Vector2f(pos_jog.x, pos_jog.y-1000));
            setVel(Vector2f(0.f, 4.f*coef_vel));
        }

        void Meteoro::reiniciar(){
            setVel(Vector2f(0.f, 0.f));
            setPos(Vector2f(-100, -100));
            setVivo(true);
        }

        void Meteoro::mover_se(){
            if(!caindo)
                setVel(Vector2f(0.f, -gravid));

            float dist1=-1, dist2=-1;
            
            if(jog1!=NULL && jog1->getVivo())
                dist1=fabs(jog1->getPos().x-getPos().x);

            if(jog2!=NULL && jog2->getVivo())
                dist2=fabs(jog2->getPos().x-getPos().x);

            if((dist1<RAIO && dist1!=-1) || (dist2<RAIO && dist2!=-1)){
                cair();
                caindo=true;
            }
        }

        void Meteoro::colidir(Entidade* outro, Vector2f ds){
            if(outro!=NULL){
                if(outro->getId() == 'j' || outro->getId() == 'g'){//jogadores
                    static_cast<Personagem*>(outro)->sofrerDano(getDano());
                    setVivo(false);
                }
                else if(outro->getId()=='b')//bloco
                    setVivo(false);
            }
        }
    };
};