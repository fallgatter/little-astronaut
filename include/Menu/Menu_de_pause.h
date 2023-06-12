#pragma once
#include"Menu.h"

namespace Menus{
    class Menu_de_pause : public Menu{
        private:
            Text txt;
        public:
            Menu_de_pause(int id = 's');
            ~Menu_de_pause();
    };
}using  namespace Menus;
