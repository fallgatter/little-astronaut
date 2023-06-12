//Cabeçalhos Padrões:
#include<math.h>

//Cabeçalhos Próprios:
#include"..\include\Jogo.h"

Jogo::Jogo(){
    executar();
}

Jogo::~Jogo(){
    
}

void Jogo::criarLua(){
    moon.criarMapa();
    moon.executar();
}

void Jogo::criarMarte(){
    mars.criarMapa();
    mars.executar();
}

void Jogo::executar(){
    int selecionador;
    Menus::Menu mn;

        int opcao;
        opcao= mn.selecionar() + 1;
        if(opcao>=1 && opcao <= 2 ){
            moon.setquantJog(opcao);
            criarLua();
        }
        if(opcao> 2 && opcao <= 4){
            mars.setquantJog(opcao-2);
            criarMarte();
        }
    }



    
