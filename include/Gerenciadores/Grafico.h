#pragma once
#include<iostream>
//Cabeçalhos Padrões:
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;

//Cabeçalhos Próprios:
//#include"../Entidades/Personagens/Jogador.h"
#include<list>


namespace Gerenciadores{
    class Grafico{
        private:
            RenderWindow* window;
            View* view;
            //list <Texture*> texturas; por enquanto conhecimento do player
            Clock clock;
            static Grafico* P;
            float dt;
            Grafico();
        public:
            ~Grafico();
            static Grafico* Singleton();
            RenderWindow* getWindow() const;
            View getView() const;
            //void loadTexture();
            void setView(View* VW);
            void setViewPos(Vector2f PO);
            void display();
            void clear();
            void closeWindow();
            void drawn(Sprite sprtaux);
            void updateTime();
            float getDt();
            void render(Sprite* body);
            bool isopen();
            void setWindow(RenderWindow* wnd);
    };
}using namespace Gerenciadores;