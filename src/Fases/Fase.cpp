//Cabeçalhos Próprios:
#include"../../include/Fases/Fase.h"

namespace Fases{
    Fase::Fase(int ID, float GRAVIDADE): 
        Ente(ID), gravidade(GRAVIDADE)
    {
        Ge=Ge->Singleton();
    }

    Fase::~Fase(){

    }

    void Fase::criarEntidade(int letra, Vector2f POS, int rand){ //fuck char
        Vector2f base=Vector2f(POS.x*48.0f, POS.y*48.0f);
        switch(letra){
            case('j'):{//jogador
                jog1 = new Jogador(Vector2f(base), letra);
                LE.incluir(jog1);
                Inimigo::setJog(jog1, letra);
                Meteoro::setJog(jog1, letra);
                break;
            }
            case('g'):{//jogador
                jog2 = new Jogador(Vector2f(base), letra);
                LE.incluir(jog2);
                Inimigo::setJog(jog2, letra);
                Meteoro::setJog(jog2, letra);
                break;
            }
            case('a'):{//alien
                Alien* alienAux;
                alienAux=new Alien(Vector2f(base), rand);
                LE.incluir(alienAux);
                vector<Projetil*>::iterator it;
                for(it=alienAux->getTiros()->begin(); it!=alienAux->getTiros()->end(); it++)
                    LE.incluir(*(it));
                break;
            }
            case('v')://ovni 
                LE.incluir(new OVNI(Vector2f(base), rand));
                break;
            case('c'):{//gato(chefao)
                Gato* gatoAux;
                gatoAux=new Gato(Vector2f(base));
                LE.incluir(gatoAux);
                vector<Meteoro*>::iterator it;
                for(it=gatoAux->getMeteoros()->begin(); it!=gatoAux->getMeteoros()->end(); it++)
                    LE.incluir(*(it));
                break;
            }
            case('b')://bloco
                LE.incluir(new Bloco(Vector2f(POS.x*48.f, POS.y*48.f), rand, id));
                break;
            case('e')://espinho
                LE.incluir(new Espinho(Vector2f(POS.x*48.f, POS.y*48.f), rand));
                break;
            case('m')://meteoro
                LE.incluir(new Meteoro(Vector2f(POS.x*48.f, POS.y*48.f), rand));
                break;
        }
    }

    void Fase::executar(){
        int i=0, j=0;
        Gc.setList(LE);
        LE[0]->setGravidade(gravidade);
        if(pga==NULL){
            exit(1);
            cout<<"aqui2  "<<endl;
        } 
        else{
            cout<<"aqui3  "<<endl;
            while(pga->isopen() && !(this->terminada()) && Ge->selecionado_da_pausa()){

                pga->setFps(100);
                
                for(i = 0;i<LE.tamanho();i++){
                    if(LE[i]->getVivo()){
                        LE[i]->atualizar();
                    }
                }
                Gc.gerenciar();
                pga->display();
                pga->clear();
                pga->setViewPos(Vector2f(jog1->getPos().x, jog1->getPos().y/10+500));
                Ge->executar();
            }
        }
        if(this->terminada()){
            this->terminar();
        }
    }
};