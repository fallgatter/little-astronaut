#include"../../include/Menu/Menu.h"
#include"../../include/Gerenciadores/Gerenciador_Eventos.h"

namespace Menus{
    Menu::Menu(int id) : Ente(id){
        
            fonte.loadFromFile("assets\\fontes\\ARIAL.TTF");
            if(!fonte.loadFromFile("assets\\fontes\\ARIAL.TTF"))
                cout<<"não tem fonte"<<endl;
        nao_enter = 1;
        selecionado = 0;
        Text txt;
        if(id == 'm'){    
            //textos = (Text*) malloc (2 * sizeof(Text));
            txt.setFont(fonte);
            txt.setFillColor(Color::White);
            txt.setString("Lua");
            txt.setCharacterSize(50);
            txt.setPosition(Vector2f(100.f,200.f));
            textos.push_back(txt);
            txt.setFont(fonte);
            txt.setFillColor(Color::White);
            txt.setString("Marte");
            txt.setCharacterSize(50);
            txt.setPosition(Vector2f(100.f,300.f));
            textos.push_back(txt);
            tam = 2;
        }
        
    }
    Menu::~Menu(){

    }
    void Menu::drawn(){
        Gerenciador_Eventos* Ge = Ge->Singleton();
        interagir();
        colorir_selecionado();
        Ge->executar();
        pga->setFps(7);
        for(int i = 0; i < tam;i++){
            pga->drawntext(textos[i]);
        }
        pga->display();
        pga->clear();
        if(!pga->isopen())
            nao_enter = 0;

    }
    int Menu::selecionar(){
        while(nao_enter){
            drawn();
        }
        return selecionado;
    }
    void Menu::colorir_selecionado(){
        for(int i=0;i<tam;i++){
            textos[i].setFillColor(Color::White);
            if(i == selecionado)
                textos[i].setFillColor(Color::Red);
        }
    }
    
    void Menu::interagir(){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) ){
            selecionado++;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) ){
            selecionado--;
        }       
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) ){
            nao_enter = 0;
        }
        if(selecionado >= tam)
            selecionado = 0;
        else if(selecionado < 0)
            selecionado = tam-1;
    }
    bool Menu::next(){
        return nao_enter;
    }
    
}using namespace Menus;