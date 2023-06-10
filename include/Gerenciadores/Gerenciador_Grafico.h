#pragma once

//Cabeçalhos Padrões:
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;

namespace Gerenciadores{
    class Gerenciador_Grafico{
        private:
            RenderWindow* window;
            View* view;
            Clock clock;
            float dt;
            //Padrão de Projeto Singleton:
            static Gerenciador_Grafico* P;
            Gerenciador_Grafico();
        public:
            ~Gerenciador_Grafico();
            static Gerenciador_Grafico* Singleton();
            RenderWindow* getWindow() const;
            View getView() const;
            void setView(View* VW);
            void setViewPos(Vector2f PO);
            void display();
            void clear();
            void closeWindow();
            void drawn(Sprite sprtaux);
            void updateTime();
            float getDt();
            bool isopen();
            void setWindow(RenderWindow* wnd);
            void setFps(int velocidade);
            void drawntext(Text txt);
    };
}using namespace Gerenciadores;