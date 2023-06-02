#include"../../../include/Entidades/Obstaculos/Obstaculo.h"

namespace Obstaculos{
    Obstaculo::Obstaculo(Vector2f POS, int TIPO_TEXT) : 
        Entidade(Vector2f(48.f, 48.f), POS, 'o'), tipo_text(TIPO_TEXT)
    {
        Sprite sprtemp;
        if(tipo_text<7)
            text.loadFromFile("assets\\textures\\World\\moon_ground3.png");
        else if(tipo_text>=7 && tipo_text<=9)
            text.loadFromFile("assets\\textures\\World\\moon_ground1.png");
        else if(tipo_text==10)
            text.loadFromFile("assets\\textures\\World\\moon_ground2.png");
        sprtemp.setTexture(text);
        setSprite(sprtemp);
    }
    Obstaculo::~Obstaculo(){}
    void Obstaculo::colidir(Entidade* outro, Vector2f ds){
        //cout<<"COLISAO OBS"<<endl;
        if(outro->getId()!='o'){
            Vector2f posAux=outro->getPos();  
            if(ds.x>ds.y){
                if(outro->getPos().x<getPos().x)//colisão em x
                    posAux.x+=ds.x;
                else
                    posAux.x-=ds.x;
                outro->setVel(Vector2f(0.f, outro->getVel().y));
            }
            else{
                if(outro->getPos().y<getPos().y)
                    posAux.y+=ds.y;
                else
                    posAux.y-=ds.y;
                outro->setVel(Vector2f( outro->getVel().x, 0.f));
            }
            outro->setPos(posAux);
        }
    }
} using namespace Obstaculos;