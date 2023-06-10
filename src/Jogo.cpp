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
    int opcao;
    Menus::Menu mn;
    opcao= mn.selecionar() + 1;

    //while(mn.isWindowOpen()){
        opcao= mn.selecionar() + 1;
        if(opcao==1){
            moon.criarMapa();
            moon.executar();
        }
        cout<<"here"<<endl;
        if(opcao==2){
            mars.criarMapa();
            mars.executar();
        }
    //}
}


    
