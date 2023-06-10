#include"../../include/Menu/Menu_Final.h"

namespace Menu{
    Menu_Final::Menu_Final(int Id) : Menu(id){
        Text txt;
            //textos = (Text*) malloc (2 * sizeof(Text));
            txt.setFont(fonte);
            txt.setFillColor(Color::White);
            txt.setString("Sair");
            txt.setCharacterSize(50);
            txt.setPosition(Vector2f(100.f,200.f));
            textos.push_back(txt);
            txt.setFont(fonte);
    }
    Menu_Final::~Menu_Final(){}
    void Menu_Final::set_Pontuacao(int pont){
        pontuacao = pont;
        char aux;
        string pontu;
        int i, og;
        og = pontuacao/10;
        Text txt;
        txt.setFont(fonte);
        txt.setFillColor(Color::White);
        txt.setString(pontu);
        txt.setCharacterSize(50);
        txt.setPosition(Vector2f(100.f,200.f));
        textos.push_back(txt);
        txt.setFont(fonte);
    }

}using namespace Menu;