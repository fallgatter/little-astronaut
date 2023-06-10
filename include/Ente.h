#pragma once

//Cabeçalhos Padrões:
#include<iostream>
using namespace std;
#include<SFML/Graphics.hpp>
using namespace sf;
#include<stdlib.h>
#include<time.h>
#include<math.h>

//Cabeçalhos Próprios:
#include"Gerenciadores/Gerenciador_Grafico.h"

class Ente{
    protected:
        int id;
        Gerenciador_Grafico* pga;
    public:
        Ente(int ID);
        virtual ~Ente();
        void setId(int ID);
        int getId() const;
};
