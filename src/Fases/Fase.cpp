//Cabeçalhos Próprios:
#include"../../include/Fases/Fase.h"

namespace Fases{
    Jogador* Fase::jog1(NULL);
    Jogador* Fase::jog2(NULL);

    Fase::Fase(int ID, float GRAVIDADE): 
        Ente(ID), gravidade(GRAVIDADE), pontuacao(0), Ge(Ge=Ge->Singleton())
    {
        
    }

    Fase::~Fase(){
        Ge=NULL;
    }

    void Fase::criarEntidade(int letra, Vector2f POS, int rand){ //fuck char
        Vector2f base=Vector2f(POS.x*48.0f, POS.y*48.0f);
        switch(letra){
            case('i'):{
                if(rand<7){
                    LE.incluir(new OVNI(Vector2f(base), rand));
                }
                else{
                    Alien* alienAux;
                    alienAux=new Alien(Vector2f(base), rand);
                    LE.incluir(alienAux);
                    vector<Projetil*>::iterator it;
                    for(it=alienAux->getTiros()->begin(); it!=alienAux->getTiros()->end(); it++)
                        LE.incluir(*(it));
                }
                break;
            }
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
        
    void Fase::setPontuacao(int PONTOS){
        pontuacao+=PONTOS;
    }

    int Fase::getPontuacao() const{
        return pontuacao;
    }

    void Fase::executar(){
        int i=0, j=0;
        Gc.setList(&LE);
        LE[0]->setGravidade(gravidade);
        if(pga==NULL || Ge==NULL){
            exit(1);
            cout<<"aqui2  "<<endl;
        } 
        else{
            cout<<"aqui3  "<<endl;
            while(pga->isopen() && !terminada() && Ge->selecionado_da_pausa() && !Go.getGame_Over()){

                pga->setFps(100);
                
                for(i = 0;i<LE.tamanho();i++){
                    if(LE[i]->getVivo()){
                        LE[i]->atualizar();
                    }
                    else if(LE[i]->getId() == 'j'){
                        pga->setViewPos(Vector2f(100.f,100.f));
                        Go.derrota();
                    }
                }
                Gc.gerenciar();
                pga->display();
                pga->clear();
                pga->setViewPos(Vector2f(jog1->getPos().x, jog1->getPos().y/10+500));
                Ge->executar();
            }
        }
        if(terminada()){
            if(jog1!=NULL && jog1->getVivo()){
                cout<<"Pontuação J1: "<<jog1->getPontuacao()<<endl;
                pontuacao+=jog1->getPontuacao();
            }
            
            if(jog2!=NULL && jog2->getVivo()){
                cout<<"Pontuação J2: "<<jog2->getPontuacao()<<endl;
                pontuacao+=jog2->getPontuacao();
            }
            terminar();
        }
    }
};