#pragma once

//Cabeçalhos Próprios:
#include"../Ente.h"

namespace Entidades{
    class Entidade: public Ente{
        protected:
            Vector2f tam, pos, vel;
            int dano;
            bool vivo;
            Texture text;
            Sprite sprt;
        public:
            Entidade(int DANO=0, bool VIVO=false, Vector2f TAM=Vector2f(0.f, 0.f), Vector2f POS=Vector2f(0.f, 0.f), int ID=0);
            ~Entidade();
            void setSprite(Sprite sprtaux);
            void setTam(Vector2f TAM);
            void setPos(Vector2f POS);
            void setVel(Vector2f VEL);
            void setScale(Vector2f scale);
            void setDano(int DANO);
            void setVivo(bool VIVO);
            Sprite getSprite() const;
            Vector2f getTam() const;
            Vector2f getPos() const;
            Vector2f getVel() const;
            int getDano() const;
            bool getVivo() const;
            void desacelerar();
            void gravidade();
            void atualizar();
            void confere_vel();
            virtual void mover_se()=0;
            virtual void colidir(Entidade* outro, Vector2f ds)=0; 
    };
}using namespace Entidades;