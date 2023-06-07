//Cabeçalhos Próprios:
#include"../../../include/Entidades/Obstaculos/Bloco.h"

namespace Obstaculos{
    Bloco::Bloco(Vector2f POS, int TIPO_TEXT): 
        Obstaculo(POS, 0, 'b'), tipo_text(TIPO_TEXT)
    {
        Sprite sprtemp;
        if(tipo_text<7)
            text.loadFromFile("assets\\textures\\World\\moon_ground3.png");
        else if(tipo_text>=7 && tipo_text<=9)
            text.loadFromFile("assets\\textures\\World\\moon_ground1.png");
        else if(tipo_text==10)
            text.loadFromFile("assets\\textures\\World\\moon_ground2.png");
        sprtemp.setTexture(text);
        setSprite(sprtemp); //seta scale, rect e pos
    }

    Bloco::~Bloco(){

    }
    int Bloco::gettipo_text(){
        return tipo_text;
    }

    void Bloco::mover_se(){
        vel.y -= gravid; //anula a gravidade
    }
};