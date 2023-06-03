#include"../../include/Fases/Fase.h"


namespace Fases{
    Fase::Fase(int ID): Ente(ID), pga(NULL){

    }

    Fase::~Fase(){

    }

    void Fase::criarEntidade(int letra, const Vector2f POS){ //fuck char
        Vector2f base=Vector2f(POS.x*48.0f, POS.y*48.0f);
        Entidade* ent;
        cout<<"ahere"<<letra<<endl;
        switch(letra){
            case('i')://inimigo 
                LE.EL.push(new Alien(Vector2f(base)));
                break;
            case('j')://jogador
                cout<<letra<<endl;
                LE.EL.push(new Jogador(Vector2f(base)));
                break;
            case('o')://obstaculo
                LE.EL.push(new Bloco(Vector2f(100.f,400.f)));
                break;
        }
    }

    void Fase::executar(){
        int i,j=0;
        cout<<"aqui  "<<endl;
        //LE.EL.push(new Jogador(Vector2f(100.f,0.f)));
        //LE.EL.push(new Alien(Vector2f(200.f,0.f)));
        //LE.EL.push(new Obstaculo(Vector2f(100.f,400.f)));
        if(pga==NULL){
            exit(1);
            cout<<"aqui2  "<<endl;
        }
        else{
            cout<<"aqui3  "<<endl;
            while(pga->isopen()){
                pga->setFps(100);
                for(i = 0;i<LE.EL.get_size();i++){
                    pga->drawn(LE.EL[i]->getSprite());
                    if(LE.EL[i]->getId() != 'o')
                        LE.EL[i]->mover_se();
                    
                    LE.EL[i]->desacelerar();
                }
                pga->display();
                pga->clear();
            }
        }
    }

    void Fase::setGrafico(Grafico* Pg)
    {
        pga = Pg;
    }
    void Fase::setColisoes(Colisoes* Pc){
        Pco = Pc;
    }
}