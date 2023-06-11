//Cabeçalhos Padrões:
#include<math.h>

//Cabeçalhos Próprios:
#include"..\include\Jogo.h"

Jogo::Jogo(){
    executar();
}

Jogo::~Jogo(){
    
}

void Jogo::executar(){
    int selecionador;
    Menus::Menu mn;
    //opcao= mn.selecionar() + 1;

    //while(mn.isWindowOpen()){
        selecionador= mn.selecionar() + 1;
        cout<<selecionador<<endl;
        if(selecionador == 1 || selecionador == 2){
            moon.setquantJog(selecionador);
            moon.criarMapa();
            moon.executar();
        }
        else if(selecionador > 2 && selecionador < 5){
            mars.setquantJog(selecionador - 2);
            mars.criarMapa();
            mars.executar();
        }
    //}
}


    
