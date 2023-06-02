#include"../../include/Fases/Lua.h"
#include<fstream>
using namespace std;

namespace Fases{
    Lua::Lua(int ID): Fase(ID){

    }

    Lua::~Lua(){

    }

    void Lua::criarMapa(){
        ifstream arquivo;
        string linha;
        int j=0, i=0;
        arquivo.open("assets/levels/lua.txt"); 
        cout<<"funcionou aqui"<<endl;
        if(!arquivo.is_open()){
            cout<<'1'<<endl;
        }
        while(getline(arquivo, linha)){
            for(i=0; i<linha.size(); i++){
                if(linha[i]!=' '){
                    criarEntidade(linha[i], Vector2f(i, j));
                }
            }
            j++;
        }
        arquivo.close();
    }
    
}