#include"../../include/Gerenciadores/Grafico.h"

namespace Gerenciadores{
    Grafico::Grafico(){
    }

    Grafico::~Grafico(){
        
    }
    
    
    void Grafico::display(){
        if(window->isOpen()){
            window->display();
        }
    }


    void Grafico::clear(){
        if(window->isOpen()){
            window->clear();
        }
    }

    void Grafico::closeWindow(){
        if(window->isOpen()){
            window->close();
        }
    }

    View Grafico::getView() const{
        return *view;
    }

    void Grafico::updateTime(){
        dt = clock.getElapsedTime().asSeconds();  //chamar a update time toda vez que rodar um ciclo no jogo
        clock.restart();
    }

    void Grafico::render(Sprite* thing){
        window->draw(*thing);
    }

    float Grafico::getDt(){
        return dt;
    }
    bool Grafico::isopen(){
        return window->isOpen();
    }
    void Grafico::setWindow(RenderWindow* wnd){
        window = wnd;
    }
    void Grafico::drawn(Sprite sprtaux){
        window->draw(sprtaux);
    }
    void Grafico::setView(View* VW){
        view = VW;
        window->setView(*view);
    }
    void Grafico::setViewPos(Vector2f POS){
        view->setCenter(POS);
        window->setView(*view);
    }
}using namespace Gerenciadores;