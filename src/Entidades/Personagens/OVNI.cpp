//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/OVNI.h"

namespace Entidades{
    namespace Personagens{
        OVNI::OVNI(Vector2f POS, float COEF_VEL): 
            Inimigo(POS, 'v'), coef_vel(COEF_VEL/8)
        {
            text.loadFromFile("assets\\textures\\Enemies\\ufo.png");
            sprt.setOrigin(Vector2f(0.f, -4.f));
            sprt.setTexture(text);
            sprt.setTextureRect(IntRect(0,0,16,16));
            sprt.setScale(Vector2f(3.0f,3.0f));
            sprt.setPosition(pos);
            setTam(Vector2f(48.f, 27.f));
        }
        
        OVNI::~OVNI(){
            
        }
    
        void OVNI::perseguir(Vector2f dist){
            if(jog!=NULL && jog->getVivo()){
                if(dist.x>0 && dist.y>0)
                    setVel(Vector2f(0.5f+coef_vel, 0.5f+coef_vel));
                else if(dist.x<0 && dist.y>0)
                    setVel(Vector2f(-0.5f-coef_vel, 0.5f+coef_vel));
                else if(dist.x<0 && dist.y<0)
                    setVel(Vector2f(-0.5f-coef_vel, -0.5f-coef_vel));
                else if(dist.x>0 && dist.y<0)
                    setVel(Vector2f(0.5f+coef_vel, -0.5f-coef_vel));
            }   
        }

        void OVNI::mover_se(){
            if(jog!=NULL && jog->getVivo()){
                Vector2f dist;
                dist.x=jog->getPos().x-getPos().x;
                dist.y=jog->getPos().y-getPos().y;
                if(fabs(dist.x)<300.0 && fabs(dist.y)<300.0)
                    perseguir(dist);
                else
                    setVel(Vector2f(0.f, -0.1f));
            }
        }
    };
};