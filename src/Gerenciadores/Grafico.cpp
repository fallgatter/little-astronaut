#include"../../include/Gerenciadores/Grafico.h"

namespace Gerenciadores{
    Grafico* Grafico::P = NULL;

    Grafico::Grafico(): window(NULL){
    }

    Grafico::~Grafico(){
        
    }
    Grafico* Grafico::Singleton(){
        if(P == NULL){
            P = new Grafico();
        }
        return P;
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
        if(window)
            return window->isOpen();
        return 0;
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
    void Grafico::setFps(int velocidade){
        window->setFramerateLimit(velocidade);
    }

}using namespace Gerenciadores;