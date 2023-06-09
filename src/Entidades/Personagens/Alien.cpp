//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Alien.h"

#define RAIO_PERSEGUIR 400
#define RAIO_ATIRAR 250

namespace Entidades{
    namespace Personagens{
        Alien::Alien(Vector2f POS, int TIPO_TEXT): 
            Inimigo(POS, 'a'), tipo_text(TIPO_TEXT), municao(5), dt(0), recarregando(false)
        {
            Sprite sprtemp;
            if(tipo_text<8)
                text.loadFromFile("assets\\textures\\Enemies\\green_alien.png");
            else
                text.loadFromFile("assets\\textures\\Enemies\\grey_alien.png");
            sprtemp.setTexture(text);
            setSprite(sprtemp); //seta scale, rect e pos

            int i;
            for(i=0; i<municao; i++){
                tiros.push_back(new Projetil(TIPO_TEXT));
            }
        }   
        
        Alien::~Alien(){
            
        }

        vector<Projetil*> *Alien::getTiros(){
            return &tiros;
        }
        
        void Alien::atirar(Vector2f dist){
            if((!municao || recarregando) && !(dt%35)){
                municao++;
                recarregando=true;
                if(municao==5)
                    recarregando=false;
            }
            else if(!recarregando){
                if(dist.x<0 && dist.x>-RAIO_ATIRAR && fabs(dist.y)<96 && municao && !(dt%200)){
                    tiros[municao-1]->lancar(Vector2f(-3.5f, 0.f), Vector2f(getPos().x, getPos().y));
                    municao--;
                }
                else if(dist.x>0 && dist.x<RAIO_ATIRAR && fabs(dist.y)<96 && municao && !(dt%200)){
                    tiros[municao-1]->lancar(Vector2f(3.5f, 0.f), Vector2f(getPos().x, getPos().y));
                    municao--;
                }
            }
            dt++;
            if(dt==201)
                dt=1;
        }

        void Alien::perseguir(Vector2f dist){
            atirar(dist);
            vel.x=0.0;
            if(!recarregando){
                if(dist.x>RAIO_ATIRAR)
                    setVel(Vector2f(1.f, vel.y));
                else if(dist.x<-RAIO_ATIRAR)
                    setVel(Vector2f(-1.f, vel.y));
                else
                    setVel(Vector2f(0.f, vel.y));
            }
        }

        void Alien::mover_se(){
            Vector2f dist1=Vector2f(0.f, 0.f);
            Vector2f dist2=Vector2f(0.f, 0.f);
            int norm1=RAIO_PERSEGUIR, norm2=RAIO_PERSEGUIR;
            
            if(jog1!=NULL && jog1->getVivo()){
                dist1.x=jog1->getPos().x-getPos().x;
                dist1.y=jog1->getPos().y-getPos().y;
                norm1=sqrt(pow((fabs(dist1.x)), 2) + pow((fabs(dist1.y)), 2));
            }
            if(jog2!=NULL && jog2->getVivo()){
                dist2.x=jog2->getPos().x-getPos().x;
                dist2.y=jog2->getPos().y-getPos().y;
                norm2=sqrt(pow((fabs(dist2.x)), 2) + pow((fabs(dist2.y)), 2));
            }

            if((jog1!=NULL && jog1->getVivo()) && norm1<norm2 && fabs(dist1.x)<RAIO_PERSEGUIR && fabs(dist1.y)<RAIO_PERSEGUIR)
                perseguir(dist1);
            
            else if((jog2!=NULL && jog2->getVivo()) && norm2<norm1 && fabs(dist2.x)<RAIO_PERSEGUIR && fabs(dist2.y)<RAIO_PERSEGUIR)
                perseguir(dist2);    
        }
    };
};