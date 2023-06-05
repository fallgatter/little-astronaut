//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Alien.h"

namespace Entidades{
    namespace Personagens{
        Alien::Alien(Vector2f POS, int TIPO_TEXT): 
            Inimigo(POS, 'a'), tipo_text(TIPO_TEXT)
        {
            Sprite sprtemp;
            if(tipo_text<8)
                text.loadFromFile("assets\\textures\\Enemies\\green_alien.png");
            else
                text.loadFromFile("assets\\textures\\Enemies\\grey_alien.png");
            sprtemp.setTexture(text);
            setSprite(sprtemp); //seta scale, rect e pos
        }
        
        Alien::~Alien(){
            
        }
        
        void Alien::atirar(){

        }

        /*void Alien::perseguir(){
            if(jog!=NULL){
                if(jog->getPos().x>getPos().x)
                    setVel(Vector2f(0.2f, 0.f));
                else
                    setVel(Vector2f(-0.2f, 0.f));
            }   
        }

        void Alien::mover_se(){
            if(jog!=NULL){
                if(fabs(jog->getPos().x-getPos().x)<100.0 && fabs(jog->getPos().y-getPos().y)<100.0)
                    perseguir();
            }
        }*/
    };
};