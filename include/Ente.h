#pragma once

class Ente{
    protected:
        int id;
    public:
        Ente(int ID);
        ~Ente();
        int getId() const;
        void setId(int idaux);
};
