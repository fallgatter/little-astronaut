#pragma once
#include"Menu.h"

namespace Menu{
    class Game_Over : public Menu{
        private:
            bool game_over;
        public:
           Game_Over(int Id='g');
           ~Game_Over();
           bool getGame_Over(); 
           void derrota();
    };
}using namespace Menu;