#pragma once 
#include"Menu.h"

namespace Menu{
    class Menu_Personagens: public Menu{
        private:
            int jogadores;
        public:
            Menu_Personagens(int Id='s');
            ~Menu_Personagens();
            int get_Personagens();
    };
} using namespace Menu;