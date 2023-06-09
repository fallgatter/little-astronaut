#include"../../../include/Entidades/Obstaculos/Espinho.h"
#include"../../../include/Entidades/Personagens/Personagem.h"

namespace Entidades{
    namespace Obstaculos{
        Espinho::Espinho(Vector2f POS, int AFIACAO): 
            Obstaculo(POS, true, 'e')
        {
            text.loadFromFile("assets\\textures\\World\\Moon\\moon_thorns.png");
            sprt.setTexture(text);
            dano=1+(AFIACAO/10);
        }

        Espinho::~Espinho(){

        }

        void Espinho::mover_se(){
            vel.y -= gravid;
        }

        void Espinho::colidir(Entidade* outro, Vector2f ds){
            if(outro->getId() == 'j' || outro->getId() == 'g'){
                if(outro->getVel().x != 0){ //só sofre dano se estiver se movendo contra o espinho, parado nele não tem problema
                    if(rand()%70 == 1)
                        static_cast<Personagem*>(outro)->sofrerDano(getDano());
                    outro->setVel(Vector2f(outro->getVel().x*0.9, outro->getVel().y*0.9));
                }
            }
        }
    };
};