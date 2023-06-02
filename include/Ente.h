#pragma once
#include<iostream>
using namespace std;


class Ente{
    protected:
        int id;

    public:
        Ente(int ID);
        ~Ente();
        int getId() const;
        void setId(int idaux);
};
