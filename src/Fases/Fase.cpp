//Cabeçalhos Próprios:
#include"../../include/Fases/Fase.h"

namespace Fases{
    Fase::Fase(int ID): 
        Ente(ID)
    {
        Ge=Ge->Singleton();
    }

    Fase::~Fase(){

    }

    void Fase::criarEntidade(int letra, Vector2f POS, int rand){ //fuck char
        Vector2f base=Vector2f(POS.x*48.0f, POS.y*48.0f);
        switch(letra){
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
            case('j')://jogador
                jog = new Jogador(Vector2f(base));
                LE.incluir(jog);
                Inimigo::setJog(jog);
                break;
            case('b')://obstaculo
                LE.incluir(new Bloco(Vector2f(POS.x*48.f, POS.y*48.f), rand));
                break;
        }
    }

    void Fase::executar(){
        int i=0, j=0;
        Gc.setList(LE);
        if(pga==NULL){
            exit(1);
            cout<<"aqui2  "<<endl;
        } 
        else{
            cout<<"aqui3  "<<endl;
            while(pga->isopen()){
                
                /*Keyboard tecl;
                jog->interacao(&tecl);*/

                pga->setFps(100);
                
                for(i = 0;i<LE.tamanho();i++){
                    //pga->drawn(LE[i]->getSprite());
                    if(LE[i]->getVivo()){
                        LE[i]->atualizar();
                    }
                    //LE[i]->desacelerar();
                }
                Gc.gerenciar();
                pga->display();
                pga->clear();
                pga->setViewPos(Vector2f(jog->getPos().x, jog->getPos().y/10+500));
                Ge->executar();
                //Event event;
                //while (janela->pollEvent(event))
                //{
                    //Ge.gerenciarInput(&event);
                //}
            }
        }
    }
};