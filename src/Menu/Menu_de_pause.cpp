#include"../../include/Menu/Menu_de_pause.h"

namespace Menus{
    Menu_de_pause::Menu_de_pause(int id) : Menu(id){
        Text txt;
        //cout<<"aqui no pausa"<<endl;
            txt.setFont(fonte);
            txt.setFillColor(Color::White);
            txt.setString("Continuar");
            txt.setCharacterSize(50);
            txt.setPosition(Vector2f(100.f,200.f));
            textos.push_back(txt);
            txt.setFont(fonte);
            txt.setFillColor(Color::White);
            txt.setString("Salvar");
            txt.setCharacterSize(50);
            txt.setPosition(Vector2f(100.f,300.f));
            textos.push_back(txt);
            txt.setFont(fonte);
            txt.setFillColor(Color::White);
            txt.setString("Sair");
            txt.setCharacterSize(50);
            txt.setPosition(Vector2f(100.f,400.f));
            textos.push_back(txt);
            tam = 3;
     }
    Menu_de_pause::~Menu_de_pause(){}
};