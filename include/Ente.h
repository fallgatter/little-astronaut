#pragma once
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
#include"Gerenciadores/Grafico.h"

class Ente{
    protected:
        int id;

    public:
        Ente(int ID);
        ~Ente();
        int getId() const;
        void setId(int idaux);
};
