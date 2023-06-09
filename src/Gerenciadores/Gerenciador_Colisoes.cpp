//Cabeçalhos Próprios:
#include"../../include/Gerenciadores/Gerenciador_Colisoes.h"

namespace Gerenciadores{
    Gerenciador_Colisoes::Gerenciador_Colisoes() : 
        dinamicos(), estaticos()
    {

    }

    Gerenciador_Colisoes::~Gerenciador_Colisoes(){

    }

    void Gerenciador_Colisoes::gerenciar(){
        float x_dist=0.0, y_dist=0.0, x_hitbox=0.0, y_hitbox=0.0;
        int i=0, j=0;
        Vector2f ds; 

        for(i=0; i<dinamicos.tamanho(); i++)
            for(j=i+1; j<dinamicos.tamanho(); j++){
                Entidade *p1, *p2;
                p1=dinamicos[i];
                p2=dinamicos[j];
                if(p1->getId()==p2->getId() || (!(p1->getVivo()) || !(p2->getVivo())))
                    continue;
                x_dist=fabs(p1->getPos().x-p2->getPos().x);
                y_dist=fabs(p1->getPos().y-p2->getPos().y);
                x_hitbox=p1->getTam().x/2+p2->getTam().x/2;
                y_hitbox=p1->getTam().y/2+p2->getTam().y/2;

                if(x_dist<x_hitbox && y_dist<y_hitbox){
                    ds.x = x_dist - x_hitbox;
                    ds.y = y_dist - y_hitbox;
                    p1->colidir(p2, ds);
                    //LE.EL[j]->colidir(LE.EL[i], ds);
                }
            }   
        for(i=0; i<dinamicos.tamanho(); i++)
            for(j=0; j<estaticos.tamanho(); j++){
                Entidade *p, *o;
                p=dinamicos[i];
                o=estaticos[j];
                if(!(p->getVivo()))
                    continue;
                x_dist=fabs(p->getPos().x-o->getPos().x);
                y_dist=fabs(p->getPos().y-o->getPos().y);
                x_hitbox=p->getTam().x/2+o->getTam().x/2;
                y_hitbox=p->getTam().y/2+o->getTam().y/2;

                if(x_dist<x_hitbox && y_dist<y_hitbox){
                    ds.x = x_dist - x_hitbox;
                    ds.y = y_dist - y_hitbox;
                    p->colidir(o, ds);
                    //LE.EL[j]->colidir(LE.EL[i], ds);
                }
            }

        /*for(i=0; i<LE.EL.get_size(); i++)
            for(j=i+1; j<LE.EL.get_size(); j++){
                if(LE.EL[i]->getId()==LE.EL[j]->getId())
                    continue;
                x_dist=fabs(LE.EL[i]->getPos().x-LE.EL[j]->getPos().x);
                y_dist=fabs(LE.EL[i]->getPos().y-LE.EL[j]->getPos().y);
                x_hitbox=LE.EL[i]->getTam().x/2+LE.EL[j]->getTam().x/2;
                y_hitbox=LE.EL[i]->getTam().y/2+LE.EL[j]->getTam().y/2;

                if(x_dist<x_hitbox && y_dist<y_hitbox){
                    ds.x = x_dist - x_hitbox;
                    ds.y = y_dist - y_hitbox;
                    LE.EL[i]->colidir(LE.EL[j], ds);
                }
            }*/
    }

    void Gerenciador_Colisoes::setList(Lista_Entidades listAux){
        int i=0;
        for(i=0; i<listAux.tamanho(); i++){
            if(listAux[i]->getId()=='j' || listAux[i]->getId()=='g' || listAux[i]->getId()=='a' || listAux[i]->getId()=='v' || listAux[i]->getId()=='p' || listAux[i]->getId()=='m' || listAux[i]->getId()=='c')
                dinamicos.incluir(listAux[i]);
            else if(listAux[i]->getId()=='b' || listAux[i]->getId()=='e')
                estaticos.incluir(listAux[i]);
        }
    }
};