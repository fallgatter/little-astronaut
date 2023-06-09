//Cabeçalhos Padrões:
#include<fstream>
using namespace std;

//Cabeçalhos Próprios:
#include"../../include/Fases/Marte.h"


namespace Fases{
    Marte::Marte(int ID): 
        Fase(ID, 0.05), chefao(NULL)
    {
        
    }

    Marte::~Marte(){
        chefao=NULL;
    }

    void Marte::criarMapa(){
        ifstream arquivo;
        srand(time(NULL));
        string linha;
        int j=0, i=0;
        arquivo.open("assets/levels/marte.txt"); 
        if(!arquivo.is_open()){
            cout<<"Level nao abriu"<<endl;
        }
        while(getline(arquivo, linha)){
            for(i=0; i<linha.size(); i++){
                if(linha[i]!=' ' && linha[i]!='c'){
                    criarEntidade(linha[i], Vector2f(i, j), rand()%11);
                }
                else if(linha[i]=='c'){
                    chefao=new Gato(Vector2f(i*48.0f, j*48.0f));
                    LE.incluir(chefao);
                    vector<Meteoro*>::iterator it;
                    for(it=chefao->getMeteoros()->begin(); it!=chefao->getMeteoros()->end(); it++)
                        LE.incluir(*(it));
                }
            }
            j++;
        }
        arquivo.close();
    }

    bool Marte::terminada(){
        if(chefao!=NULL)
            if(!(chefao->getVivo()))
                return true;
        return false;
    }

    void Marte::terminar(){
        cout<<"Pontuação Total: "<<pontuacao<<endl;
    }
};