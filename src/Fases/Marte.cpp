//Cabeçalhos Padrões:
#include<fstream>
using namespace std;

//Cabeçalhos Próprios:
#include"../../include/Fases/Marte.h"


namespace Fases{
    Marte::Marte(int ID): 
        Fase(ID)
    {
        gravidade = 0.12;
    }

    Marte::~Marte(){

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
                if(linha[i]!=' '){
                    criarEntidade(linha[i], Vector2f(i, j), rand()%11);
                }
            }
            j++;
        }
        arquivo.close();
    }
};