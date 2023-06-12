#pragma once
#include"../Ente.h"
#include<vector>

#define quant_menus 2;

namespace Menus{
    class Menu : public Ente{
        protected:
            Vector2f tamanho, pos;
            vector<Text> textos;
            Font fonte;
            int aberto, selecionado, tam;
            bool nao_enter;//o nextt verifica se o enter foi precionado ou n
            Sprite sprt;
            Texture textura;
        public:
            Menu(int id='m');
            virtual ~Menu();
            int selecionar();
            void interagir();
            void colorir_selecionado();
            void drawn();
            bool next();
            bool isWindowOpen();

    };
}using namespace Menus;