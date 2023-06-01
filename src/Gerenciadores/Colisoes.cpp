#include"../../include/Gerenciadores/Colisoes.h"
#include<math.h>

namespace Gerenciadores{
    Colisoes::Colisoes() : LE(){}
    Colisoes::~Colisoes(){}
    void Colisoes::gerenciar(){
         float x_dist=0.0, y_dist=0.0, x_hitbox=0.0, y_hitbox=0.0;
        int i=0, j=0;
        Vector2f ds; 

        for(i=0; i<LE.EL.get_size(); i++)
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
                    LE.EL[j]->colidir(LE.EL[i], ds);
                }
        }
    }
    void Colisoes::setList(Lista_Entidades listAux){
        LE=listAux;
    }
} using namespace Gerenciadores;