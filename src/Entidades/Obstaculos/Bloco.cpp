//Cabeçalhos Próprios:
#include"../../../include/Entidades/Obstaculos/Bloco.h"

namespace Entidades{
    namespace Obstaculos{
        Bloco::Bloco(Vector2f POS, int TIPO_TEXT, int ID): 
            Obstaculo(POS, false, 'b'), tipo_text(TIPO_TEXT)
        {
            Sprite sprtemp;
            if(ID=='L'){//Lua
                if(tipo_text<7)
                    text.loadFromFile("assets\\textures\\World\\Moon\\moon_ground3.png");
                else if(tipo_text>=7 && tipo_text<=9)
                    text.loadFromFile("assets\\textures\\World\\Moon\\moon_ground1.png");
                else if(tipo_text==10){
                    text.loadFromFile("assets\\textures\\World\\Moon\\moon_ground2.png");
                    rugoso=true;
                }
            }
            if(ID=='M'){//Marte
                if(tipo_text<7)
                    text.loadFromFile("assets\\textures\\World\\Mars\\mars_ground3.png");
                else if(tipo_text>=7 && tipo_text<=9)
                    text.loadFromFile("assets\\textures\\World\\Mars\\mars_ground1.png");
                else if(tipo_text==10){
                    text.loadFromFile("assets\\textures\\World\\Mars\\mars_ground2.png");
                    rugoso=true;
                }
            }
            sprtemp.setTexture(text);
            setSprite(sprtemp);//seta scale, rect e pos
        }

        Bloco::~Bloco(){

        }

        void Bloco::mover_se(){
            vel.y -= gravid;
        }

        void Bloco::colidir(Entidade* outro, Vector2f ds){
            if(outro!=NULL){
                if(outro->getId()!='b' && outro->getId()!='p'){//entidades dinâmicas(-projetil)
                    Vector2f posAux=outro->getPos();  
                    if(ds.x>ds.y){//colisão em x
                        if(outro->getPos().x<getPos().x)
                            posAux.x+=ds.x;
                        else
                            posAux.x-=ds.x;
                        if(rugoso)
                            posAux.x*=0.5;
                        outro->setVel(Vector2f(0.f, outro->getVel().y));
                    }
                    else{//colisão em y
                        if(outro->getPos().y<getPos().y)
                            posAux.y+=ds.y;
                        else
                            posAux.y-=ds.y;
                        outro->setVel(Vector2f(outro->getVel().x, 0.f));
                    }
                    outro->setPos(posAux);
                }
                else if(outro->getId() == 'p'){//projétil
                    outro->setVivo(false);
                }
            }
        }
    };
};