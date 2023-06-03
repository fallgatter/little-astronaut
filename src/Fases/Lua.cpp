//Cabeçalhos Padrões:
#include<fstream>
using namespace std;

//Cabeçalhos Próprios:
#include"../../include/Fases/Lua.h"


namespace Fases{
    Lua::Lua(int ID): 
        Fase(ID)
    {

    }

    Lua::~Lua(){

    }

    void Lua::criarMapa(){
        ifstream arquivo;
        srand(time(NULL));
        string linha;
        int j=0, i=0;
        arquivo.open("assets/levels/lua.txt"); 
        if(arquivo.is_open())
            cout<<"funcionou aqui"<<endl;
        if(!arquivo.is_open()){
            cout<<'1'<<endl;
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