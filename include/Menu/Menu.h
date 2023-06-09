#pragma once
#include"../Ente.h"


#define quant_menus 2;

namespace Menus{
    class Menu : public Ente{
        protected:
            Vector2f tamanho, pos;
            Text textos[2];
            Font fonte;
            int aberto, selecionado;
            bool nao_enter;//o nextt verifica se o enter foi precionado ou n
            Sprite sprt;
            Texture textura;
        public:
            Menu(Vector2f TAM = Vector2f(300.f,300.f));
            ~Menu();
            int selecionar_fase();
            void interagir();
            void colorir_selecionado();
            void drawn();
            bool next();

    };
}using namespace Menus;