#pragma once
#include"Menu.h"

namespace Menu{
    class Menu_Final: public Menu{
        private:
            int pontuacao;
        public:
            Menu_Final(int Id='f');
            ~Menu_Final();
            void Mostrar_Pontuacao();
            void set_Pontuacao(int pont);
    };
}using namespace Menu;