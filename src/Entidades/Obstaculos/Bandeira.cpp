//Cabeçalhos Próprios:
#include"../../../include/Entidades/Obstaculos/Bandeira.h"

namespace Entidades{
    namespace Obstaculos{
        Bandeira::Bandeira(Vector2f POS, int TIPO_TEXT): 
            Obstaculo(POS, false, 'f'), tipo_text(TIPO_TEXT), p1(false)
        {
            if(tipo_text<7)
                text.loadFromFile("assets\\textures\\Flags\\flag_brazil.png");
            else if(tipo_text>=7 && tipo_text<=9)
                text.loadFromFile("assets\\textures\\Flags\\flag_usa.png");
            else if(tipo_text==10)
                text.loadFromFile("assets\\textures\\Flags\\flag_utf.png");
            sprt.setTexture(text);
            sprt.setOrigin(Vector2f(0.f, 10.f));
            setTam(Vector2f(39.f, 63.f));
        }

        Bandeira::~Bandeira(){

        }

        void Bandeira::setP1(bool P1){
            p1=P1;
        }

        bool Bandeira::getP1() const{
            return p1;
        }

        void Bandeira::mover_se(){
            vel.y -= gravid;
        }

        void Bandeira::colidir(Entidade* outro, Vector2f ds){
            if(outro!=NULL){
                if(outro->getId()=='j' || outro->getId()=='g')//jogadores
                    p1=true;
            }
        }
    };
};