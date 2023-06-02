#include"../../include/Fases/Fase.h"


namespace Fases{
    Fase::Fase(int ID): Ente(ID){

    }

    Fase::~Fase(){

    }

    void Fase::criarEntidade(char letra, const Vector2f POS){
        Vector2f base=Vector2f(POS.x*48.0f, POS.y*48.0f);
        Entidade* ent;
        switch(letra){
            case('i')://inimigo
                
                break;
            case('j')://jogador
                break;
            case('o')://obstaculo

                break;
        }
    }

    void Fase::executar(){
        sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
        //sf::CircleShape shape(100.f);
        //shape.setFillColor(sf::Color::Green);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            //window.draw(shape);
            window.draw(LE.EL[0]->getSprite());
            window.display();
        }
        
        
        }

        void Fases::Fase::setGrafico(Grafico *Pg)
        {
            Pga = Pg;
        }
        void Fase::setColisoes(Colisoes* Pc){
            Pco = Pc;
        }
}