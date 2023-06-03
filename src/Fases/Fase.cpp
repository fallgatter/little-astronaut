//Cabeçalhos Próprios:
#include"../../include/Fases/Fase.h"

namespace Fases{
    Fase::Fase(int ID): 
        Ente(ID)
    {

    }

    Fase::~Fase(){

    }

    void Fase::criarEntidade(int letra, Vector2f POS, int tipo_text){ //fuck char
        Vector2f base=Vector2f(POS.x*48.0f, POS.y*48.0f);
        cout<<"ahere"<<letra<<endl;
        switch(letra){
            case('i')://inimigo 
                LE.incluir(new Alien(Vector2f(base), tipo_text));
                break;
            case('j')://jogador
                cout<<letra<<endl;
                jog = new Jogador(Vector2f(base));
                LE.incluir(jog);
                break;
            case('b')://obstaculo
                LE.incluir(new Bloco(Vector2f(POS.x*48.f, POS.y*48.f), tipo_text));
                break;
        }
    }

    void Fase::executar(){
        int i=0, j=0;
        cout<<"aqui  "<<endl;
        //LE.EL.push(new Jogador(Vector2f(100.f,0.f)));
        //LE.EL.push(new Alien(Vector2f(200.f,0.f)));
        //LE.EL.push(new Obstaculo(Vector2f(100.f,400.f)));
        Ge.setWindow(pga->getWindow());
        Pco.setList(LE);
        if(pga==NULL){
            exit(1);
            cout<<"aqui2  "<<endl;
        } 
        else{
            cout<<"aqui3  "<<endl;
            while(pga->isopen()){
                Event event;
                while (pga->getWindow()->pollEvent(event))
                {
                    Ge.gerenciarInput(&event);
                }
                Keyboard tecl;
                jog->interacao(&tecl);
                pga->setFps(100);
                for(i = 0;i<LE.tamanho();i++){
                    pga->drawn(LE[i]->getSprite());
                    if(LE[i]->getId() != 'b'){
                        LE[i]->mover_se();
                        LE[i]->desacelerar();
                    } 
                }
                Pco.gerenciar();
                pga->display();
                pga->clear();
                //Event event;
                //while (janela->pollEvent(event))
                //{
                    //Ge.gerenciarInput(&event);
                //}
            }
        }
    }

    void Fase::setGrafico(Gerenciador_Grafico* Pg){
        pga = Pg;
    }
    void Fase::setColisoes(Gerenciador_Colisoes Pc){
        Pco = Pc;
    }
};