#include"../../../include/Entidades/Obstaculos/Obstaculo.h"
#include<math.h>

namespace Obstaculos{
    Obstaculo::Obstaculo(Vector2f TAM, Vector2f POS, Vector2f VEL, Vector2f ACEL, Texture TEXT, Sprite SPRT, int ID)  : Entidade(TAM, POS,  VEL, ACEL,TEXT, SPRT,ID){}
    Obstaculo::~Obstaculo(){}
    void Obstaculo::colidir(Entidade* outro){
        
    }
} using namespace Obstaculos;