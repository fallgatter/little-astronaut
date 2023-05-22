#pragma once
#include<iostream>
//Cabeçalhos Padrões:
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;

//Cabeçalhos Próprios:
#include"../Entidades/Jogador.h"
#include<list>


namespace Gerenciadores{
    class Grafico{
        private:
            RenderWindow* window;
            View view;
            //list <Texture*> texturas; por enquanto conhecimento do player
             Clock clock;
            float dt;
        public:
            Grafico();
            ~Grafico();
            RenderWindow* getWindow() const;
            View getView() const;
            //void loadTexture();
            void display();
            void clear();
            void closeWindow();
            void show();
            void updateTime();
            float getDt();
            void render(Sprite* body);
            bool isopen();
            void setWindow(RenderWindow* wnd);
    };
}using namespace Gerenciadores;