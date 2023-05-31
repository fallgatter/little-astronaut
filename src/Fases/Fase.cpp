#include"../../include/Fases/Fase.h"

namespace Fases{
    Fase::Fase(int ID): Ente(ID){

    }

    Fase::~Fase(){

    }

    void Fase::criarEntidade(char letra, const Vector2f POS){
        Vector2f base=Vector2f(POS.x*48.0f, POS.y*48.0f);
        switch(letra){
            case('i')://inimigo
                
                break;
            case('j')://jogador

                break;
            case('o')://obstaculo

                break;
        }
    }

    void Fase::executar(){

    }
}