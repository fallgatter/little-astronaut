//Cabeçalhos Padrões:
#include<fstream>
using namespace std;

//Cabeçalhos Próprios:
#include"../../include/Fases/Lua.h"


namespace Fases{
    Lua::Lua(int ID): 
        Fase(ID, 0.08), flag(NULL)
    {

    }

    Lua::~Lua(){
        flag=NULL;
    }

    void Lua::criarMapa(){
        ifstream arquivo;
        srand(time(NULL));
        string linha;
        int j=0, i=0;
        arquivo.open("assets/levels/lua.txt"); 
        if(!arquivo.is_open()){
            cout<<"Level nao abriu"<<endl;
        }
        while(getline(arquivo, linha)){
            for(i=0; i<linha.size(); i++){
                if(linha[i]!=' ' && linha[i]!='f'){
                    criarEntidade(linha[i], Vector2f(i, j), rand()%11);
                }
                else if(linha[i]=='f'){
                    flag=new Bandeira(Vector2f(i*48.0f, j*48.0f), rand()%11);
                    LE.incluir(flag);
                }
            }
            j++;
        }
        arquivo.close();
    }

    bool Lua::terminada(){
        if(flag!=NULL)
            if(flag->getP1())
                return true;
        return false;
    }

    void Lua::terminar(){
        Marte mars;
        mars.setPontuacao(pontuacao);
        mars.criarMapa();
        mars.executar();
    }
};