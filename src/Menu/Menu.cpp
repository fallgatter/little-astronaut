#include"../../include/Menu/Menu.h"
#include"../../include/Gerenciadores/Gerenciador_Eventos.h"

namespace Menus{
    Menu::Menu(Vector2f Tam) : Ente('m'){
        fonte.loadFromFile("assets\\fontes\\ARIAL.TTF");
        if(!fonte.loadFromFile("assets\\fontes\\ARIAL.TTF"))
            cout<<"não tem fonte"<<endl;
        
        textos[0].setFont(fonte);
        textos[0].setFillColor(Color::White);
        textos[0].setString("Lua");
        textos[0].setCharacterSize(50);
        textos[0].setPosition(Vector2f(100.f,200.f));

        textos[1].setFont(fonte);
        textos[1].setFillColor(Color::White);
        textos[1].setString("Marte");
        textos[1].setCharacterSize(50);
        textos[1].setPosition(Vector2f(100.f,300.f));
        nao_enter = 1;
        selecionado = 0;
    }
    Menu::~Menu(){

    }
    void Menu::drawn(){
        Gerenciador_Eventos* Ge = Ge->Singleton();
        interagir();
        colorir_selecionado();
        Ge->executar();
        pga->drawntext(textos[0]);
        pga->drawntext(textos[1]);
        pga->display();
        pga->clear();
        if(!pga->isopen())
            nao_enter = 0;

    }
    int Menu::selecionar_fase(){
        while(nao_enter){
            drawn();
        }
        return selecionado;
    }
    void Menu::colorir_selecionado(){
        for(int i=0;i<2;i++){
            textos[i].setFillColor(Color::White);
            if(i == selecionado)
                textos[i].setFillColor(Color::Blue);
        }
    }
    
    void Menu::interagir(){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) ){
            selecionado=1;
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) ){
            selecionado=0;
        }       
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) ){
            nao_enter = 0;
        }
    }
    bool Menu::next(){
        return nao_enter;
    }
    
}using namespace Menus;