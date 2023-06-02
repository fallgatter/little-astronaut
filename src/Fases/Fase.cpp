#include"../../include/Fases/Fase.h"


namespace Fases{
    Fase::Fase(int ID): Ente(ID){

    }

    Fase::~Fase(){

    }

    void Fase::criarEntidade(int letra, const Vector2f POS){ //fuck char
        Vector2f base=Vector2f(POS.x*48.0f, POS.y*48.0f);
        Entidade* ent;
        cout<<'a'<<letra<<endl;
        switch(letra){
            case('i')://inimigo 
                LE.EL.push(new Inimigo(Vector2f(base)));
                break;
            case('j')://jogador
                LE.EL.push(new Jogador(Vector2f(base)));
                break;
            case('o')://obstaculo

                break;
        }
    }

    void Fase::executar(){
        int i,j=0;
        while(pga->isopen()){
            for(i = 0;i<LE.EL.get_size();i++){
                pga->drawn(LE.EL[i]->getSprite());
            }
            pga->display();
            pga->clear();
        }
    }

    void Fases::Fase::setGrafico(Grafico *Pg)
    {
        pga = Pg;
    }
    void Fase::setColisoes(Colisoes* Pc){
        Pco = Pc;
    }
}