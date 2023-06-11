#include"../../include/Menu/Menu_Personagens.h"

namespace Menu{
    Menu_Personagens::Menu_Personagens(int Id) : Menu(Id){
        Text txt;
        txt.setFont(fonte);
        txt.setFillColor(Color::White);
        txt.setString("1 Jogador");
        txt.setCharacterSize(50);
        txt.setPosition(Vector2f(100.f,200.f));
        textos.push_back(txt);
        txt.setFont(fonte);
        txt.setFillColor(Color::White);
        txt.setString("2 Jogadores");
        txt.setCharacterSize(50);
        txt.setPosition(Vector2f(100.f,300.f));
        textos.push_back(txt);
        jogadores = 0;
    }
    Menu_Personagens::~Menu_Personagens(){}
    int Menu_Personagens::get_Personagens(){
        jogadores = selecionar() + 1;
        return jogadores;
    }
};