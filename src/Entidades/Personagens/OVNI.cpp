//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/OVNI.h"

#define RAIO_PERSEGUIR 300

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
            if(jog1!=NULL && jog1->getVivo()){
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
            setVel(Vector2f(0.f, -gravid));

            Vector2f dist1=Vector2f(0.f, 0.f);
            Vector2f dist2=Vector2f(0.f, 0.f);
            int norm1=RAIO_PERSEGUIR, norm2=RAIO_PERSEGUIR;
            
            if(jog1!=NULL && jog1->getVivo()){
                dist1.x=jog1->getPos().x-getPos().x;
                dist1.y=jog1->getPos().y-getPos().y;
                norm1=sqrt(pow((fabs(dist1.x)), 2) + pow((fabs(dist1.y)), 2));//norma da distancia 1
            }
            if(jog2!=NULL && jog2->getVivo()){
                dist2.x=jog2->getPos().x-getPos().x;
                dist2.y=jog2->getPos().y-getPos().y;
                norm2=sqrt(pow((fabs(dist2.x)), 2) + pow((fabs(dist2.y)), 2));//norma da distancia 2
            }

            if((jog1!=NULL && jog1->getVivo()) && fabs(dist1.x)<RAIO_PERSEGUIR && fabs(dist1.y)<RAIO_PERSEGUIR)
                perseguir(dist1);
            
            else if((jog2!=NULL && jog2->getVivo()) && fabs(dist2.x)<RAIO_PERSEGUIR && fabs(dist2.y)<RAIO_PERSEGUIR)
                perseguir(dist2);
        }
    };
};