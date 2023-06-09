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
        Texture text;
        //text.loadFromFile("assets\\textures\\World\\Moon\\moon_ground.png");
        if(id == 'm'){    
            //textos = (Text*) malloc (2 * sizeof(Text));
            txt.setFont(fonte);
            txt.setFillColor(Color::White);
            txt.setString("Lua - 1 Jogador");
            txt.setCharacterSize(50);
            txt.setPosition(Vector2f(100.f,100.f));
            textos.push_back(txt);
            txt.setFont(fonte);
            txt.setFillColor(Color::White);
            txt.setString("Lua - 2 Jogadores");
            txt.setCharacterSize(50);
            txt.setPosition(Vector2f(100.f,150.f));
            textos.push_back(txt);
            txt.setFont(fonte);
            txt.setFillColor(Color::White);
            txt.setString("Marte - 1 Jogador");
            txt.setCharacterSize(50);
            txt.setPosition(Vector2f(100.f,200.f));
            textos.push_back(txt);
            txt.setFont(fonte);
            txt.setFillColor(Color::White);
            txt.setString("Marte - 2 Jogadores");
            txt.setCharacterSize(50);
            txt.setPosition(Vector2f(100.f,250.f));
            textos.push_back(txt);
            txt.setFont(fonte);
            txt.setFillColor(Color::White);
            txt.setString("Sair");
            txt.setCharacterSize(50);
            txt.setPosition(Vector2f(100.f,300.f));
            textos.push_back(txt);
            tam = 5;
        }
        sprt.setTexture(text);
        sprt.setPosition(0.f,0.f);
        sprt.setScale(10.f,10.f);
    }
    Menu::~Menu(){
        
    }
    void Menu::drawn(){
        Gerenciador_Eventos* Ge = Ge->Singleton();
        interagir();
        colorir_selecionado();
        Ge->executar();
        pga->setFps(20);
        for(int i = 0; i < tam;i++){
            pga->drawntext(textos[i]);
        }
        pga->drawn(sprt);
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
        if(!nao_enter && selecionado == 4 && id == 'm')
            pga->closeWindow();
    }
    bool Menu::next(){
        return nao_enter;
    }
    bool Menu::isWindowOpen(){
        return pga->isopen();
    }
    
}using namespace Menus;