#include"../../include/Menu/Game_Over.h"

namespace Menu{
    Game_Over::Game_Over(int Id) : Menu(Id){
        tam = 1;
        Text txt;
        txt.setFont(fonte);
        txt.setFillColor(Color::White);
        txt.setString("Game_Over");
        txt.setCharacterSize(70);
        txt.setPosition(Vector2f(-100.f,0.f));
        textos.push_back(txt);
        game_over = 0;
    }
    Game_Over::~Game_Over(){}
    
    bool Game_Over::getGame_Over(){
        return game_over;
    }
    void Game_Over::derrota(){
        game_over = 1;
        selecionar();
    }
} using namespace Menu;