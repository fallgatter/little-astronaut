#pragma once
#include"Menu.h"

namespace Menus{
    class Menu_de_Pontuacao : public Menu{
        private:
            int pontuação;
        public:
            Menu_de_Pontuacao();
            ~Menu_de_Pontuacao();
    }; 
} using namespace Menus;