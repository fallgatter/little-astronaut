//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Alien.h"

#define RAIO_PERSEGUIR 300
#define RAIO_ATIRAR 200

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
                tiros.push_back(new Projetil());
            }
        }   
        
        Alien::~Alien(){
            
        }

        vector<Projetil*> *Alien::getTiros(){
            return &tiros;
        }
        
        void Alien::atirar(Vector2f dist){
            cout<<"atirando"<<endl;
            if((!municao || recarregando) && !(dt%25)){
                municao++;
                recarregando=true;
                if(municao==5)
                    recarregando=false;
            }
            else if(!recarregando){
                if(dist.x<0 && dist.x>-RAIO_ATIRAR && fabs(dist.y)<96 && municao && !(dt%200)){
                    tiros[municao-1]->lancar(Vector2f (-3.5f, 0.f), Vector2f(getPos().x, getPos().y+25));
                    municao--;
                }
                else if(dist.x>0 && dist.x<RAIO_ATIRAR && fabs(dist.y)<96 && municao && !(dt%200)){
                    tiros[municao-1]->lancar(Vector2f (3.5f, 0.f), Vector2f(getPos().x, getPos().y+25));
                    municao--;
                }
            }
            dt++;
            if(dt==201)
                dt=1;
        }

        void Alien::perseguir(Vector2f dist){
            if(jog!=NULL){
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
        }

        void Alien::mover_se(){
            Vector2f dist;
            if(jog!=NULL){
                dist.x=jog->getPos().x-getPos().x;
                dist.y=jog->getPos().y-getPos().y;
                if(fabs(dist.x)<RAIO_PERSEGUIR && fabs(dist.y)<RAIO_PERSEGUIR)
                    perseguir(dist);
            }
        }
    };
};