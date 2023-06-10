//Cabeçalhos Próprios:
#include"../../include/Gerenciadores/Gerenciador_Colisoes.h"

namespace Gerenciadores{
    Gerenciador_Colisoes::Gerenciador_Colisoes()
    {

    }

    Gerenciador_Colisoes::~Gerenciador_Colisoes(){
        
    }

    void Gerenciador_Colisoes::gerenciar(){
        Entidade *e1, *e2;
        Vector2f ds;
        float x_dist=0.0, y_dist=0.0, x_hitbox=0.0, y_hitbox=0.0;
        int i=0, j=0;

        for(i=0; i<dinamicos.tamanho(); i++)
            for(j=i+1; j<dinamicos.tamanho(); j++){
                e1=dinamicos[i];
                e2=dinamicos[j];
                if(e1->getId()==e2->getId() || (!(e1->getVivo()) || !(e2->getVivo())))
                    continue;
                x_dist=fabs(e1->getPos().x-e2->getPos().x);
                y_dist=fabs(e1->getPos().y-e2->getPos().y);
                x_hitbox=e1->getTam().x/2+e2->getTam().x/2;
                y_hitbox=e1->getTam().y/2+e2->getTam().y/2;

                if(x_dist<x_hitbox && y_dist<y_hitbox){
                    ds.x = x_dist - x_hitbox;
                    ds.y = y_dist - y_hitbox;
                    e1->colidir(e2, ds);
                }
            }   
        for(i=0; i<dinamicos.tamanho(); i++)
            for(j=0; j<estaticos.tamanho(); j++){
                e1=dinamicos[i];
                e2=estaticos[j];
                if(!(e1->getVivo()))
                    continue;
                x_dist=fabs(e1->getPos().x-e2->getPos().x);
                y_dist=fabs(e1->getPos().y-e2->getPos().y);
                x_hitbox=e1->getTam().x/2+e2->getTam().x/2;
                y_hitbox=e1->getTam().y/2+e2->getTam().y/2;

                if(x_dist<x_hitbox && y_dist<y_hitbox){
                    ds.x = x_dist - x_hitbox;
                    ds.y = y_dist - y_hitbox;
                    e1->colidir(e2, ds);
                }
            }
        e1=NULL;
        e2=NULL;
    }

    void Gerenciador_Colisoes::setList(Lista_Entidades* listAux){
        if(listAux!=NULL){
            int i=0;
            for(i=0; i<listAux->tamanho(); i++){
                if((*listAux)[i]!=NULL){
                    if((*listAux)[i]->getId()=='j' || (*listAux)[i]->getId()=='g' || (*listAux)[i]->getId()=='a' || (*listAux)[i]->getId()=='v' || (*listAux)[i]->getId()=='p' || (*listAux)[i]->getId()=='m' || (*listAux)[i]->getId()=='c')
                        dinamicos.incluir((*listAux)[i]);
                    else if((*listAux)[i]->getId()=='b' || (*listAux)[i]->getId()=='e' || (*listAux)[i]->getId()=='f')
                        estaticos.incluir((*listAux)[i]);
                }
            }
        }
    }
};