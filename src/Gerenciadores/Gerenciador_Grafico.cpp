//Cabeçalhos Próprios:
#include"../../include/Gerenciadores/Gerenciador_Grafico.h"

namespace Gerenciadores{
    Gerenciador_Grafico* Gerenciador_Grafico::P = NULL;

    Gerenciador_Grafico::Gerenciador_Grafico(){
        window = new RenderWindow(sf::VideoMode(800.0f, 600.0f), "little astronaut", Style::Close);
        view = new View(sf::FloatRect(0.f, 0.f, 1000.f, 1000.f));
    }

    Gerenciador_Grafico::~Gerenciador_Grafico(){
        window=NULL;
        view=NULL;
    }

    RenderWindow* Gerenciador_Grafico::getWindow() const{
        if(window!=NULL){
            return window;
        }
        else
            exit;
        return NULL;
    }

    Gerenciador_Grafico* Gerenciador_Grafico::Singleton(){
        if(P == NULL){
            P = new Gerenciador_Grafico();
        }
        return P;
    }
    
    void Gerenciador_Grafico::display(){
        if(window!=NULL)
            if(window->isOpen())
                window->display();
    }


    void Gerenciador_Grafico::clear(){
        if(window!=NULL)
            if(window->isOpen())
                window->clear();
    }

    void Gerenciador_Grafico::closeWindow(){
        if(window!=NULL)
            if(window->isOpen())
                window->close();
    }

    View Gerenciador_Grafico::getView() const{//erro
        return *view;
    }

    void Gerenciador_Grafico::updateTime(){
        dt = clock.getElapsedTime().asSeconds();  //chamar a update time toda vez que rodar um ciclo no jogo
        clock.restart();
    }

    float Gerenciador_Grafico::getDt(){
        return dt;
    }

    bool Gerenciador_Grafico::isopen(){
        if(window!=NULL)
            return window->isOpen();
        return false;
    }

    void Gerenciador_Grafico::setWindow(RenderWindow* wnd){
        if(wnd!=NULL)
            window = wnd;
    }

    void Gerenciador_Grafico::drawn(Sprite sprtaux){
        if(window!=NULL)
            window->draw(sprtaux);
    }

    void Gerenciador_Grafico::setView(View* VW){
        if(VW!=NULL){
            view = VW;
            window->setView(*view);
        }
    }

    void Gerenciador_Grafico::setViewPos(Vector2f POS){
        if(view!=NULL){
            view->setCenter(POS);
            window->setView(*view);
        }
    }

    void Gerenciador_Grafico::setFps(int velocidade){
        if(window!=NULL)
            window->setFramerateLimit(velocidade);
    }

    void Gerenciador_Grafico::drawntext(Text txt){
        if(window!=NULL)
            window->draw(txt);
    }
}using namespace Gerenciadores;