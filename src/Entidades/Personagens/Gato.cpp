//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Gato.h"

#define RAIO_PERSEGUIR 500
#define CARGA_MAX 10

namespace Entidades{
    namespace Personagens{
        Gato::Gato(Vector2f POS): 
            Inimigo(POS, 'c'), carga(CARGA_MAX), dt(0), recarregando(false)
        {
            text.loadFromFile("assets\\textures\\Enemies\\gato_frame.png");
            sprt.setTexture(text);
            sprt.setOrigin(Vector2f(0.f, -6.f));
            setTam(Vector2f(45.f, 36.f));
            
            int i=0;
            for(i=0; i<CARGA_MAX; i++)
                meteoros.push_back(new Meteoro(Vector2f(-100, -100), 10));
            vidas=30;
        }   
        
        Gato::~Gato(){
            /*int i=0;
            for(i=0; i<CARGA_MAX; i++){
                if(meteoros[i]!=NULL)
                    delete(meteoros[i]);
            } */
            meteoros.clear();
            //a fase inclui os meteoros na lista de entidades, e a lista de entidades por sua efetua o delete.
        }

        vector<Meteoro*> *Gato::getMeteoros(){
            return &meteoros;
        }
        
        void Gato::atirar(Vector2f pos_jog){
            if((!carga || recarregando) && !(dt%50)){
                carga++;
                recarregando=true;
                if(carga==CARGA_MAX){
                    recarregando=false;
                    for(int i=0; i<CARGA_MAX; i++)
                        meteoros[i]->reiniciar();
                }
            }
            else if(!recarregando){
                if(carga && !(dt%150)){
                    meteoros[carga-1]->cair(pos_jog);
                    carga--;
                }
            }
            dt++;
            if(dt==151)
                dt=1;
        }

        void Gato::perseguir(Vector2f dist){
            setVel(Vector2f(0.f, -gravid));
            if(!recarregando){
                if(dist.x>0 && dist.y>0)
                    setVel(Vector2f(1.f, 1.f));
                else if(dist.x<0 && dist.y>0)
                    setVel(Vector2f(-1.f, 1.f));
                else if(dist.x<0 && dist.y<0)
                    setVel(Vector2f(-1.f, -1.f));
                else if(dist.x>0 && dist.y<0)
                    setVel(Vector2f(1.f, -1.f));     
            }
        }

        void Gato::mover_se(){
            setVel(Vector2f(0.f, -gravid));

            Vector2f dist1=Vector2f(0.f, 0.f);
            Vector2f dist2=Vector2f(0.f, 0.f);
            float norm1=RAIO_PERSEGUIR, norm2=RAIO_PERSEGUIR;
            
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

            if((jog1!=NULL && jog1->getVivo()) && norm1<norm2 && fabs(dist1.x)<RAIO_PERSEGUIR && fabs(dist1.y)<RAIO_PERSEGUIR){
                perseguir(dist1);
                atirar(jog1->getPos());
            }
                
            else if((jog2!=NULL && jog2->getVivo()) && norm2<norm1 && fabs(dist2.x)<RAIO_PERSEGUIR && fabs(dist2.y)<RAIO_PERSEGUIR){
                perseguir(dist2);
                atirar(jog2->getPos());
            }
        }
    };
};