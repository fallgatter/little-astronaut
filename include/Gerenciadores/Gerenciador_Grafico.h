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
            //list <Texture*> texturas; por enquanto conhecimento do player
            Clock clock;
            static Gerenciador_Grafico* P;
            float dt;
            Gerenciador_Grafico();
        public:
            ~Gerenciador_Grafico();
            static Gerenciador_Grafico* Singleton();
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
            void setFps(int velocidade);
    };
}using namespace Gerenciadores;