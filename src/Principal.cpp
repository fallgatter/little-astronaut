#include"..\include\Principal.h"

Principal::Principal():
    janela(sf::VideoMode(800.0f, 600.0f), "little astronaut")
{
    executar();
}

Principal::~Principal(){

}

void Principal::executar(){
    while(janela.isOpen()){

    }
}

