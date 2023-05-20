#include<iostream>
#include<SFML/Graphics.hpp>
#include"include\Principal.h"

using namespace sf;
using namespace std;

/*class Entidade{
    protected:
        Vector2f cordenada, tamanho;
        Texture textura;
        Sprite sprt;
    public:
        Entidade(Vector2f coord, Vector2f tam, Texture txt) : cordenada(coord), tamanho(tam), textura(txt){
            sprt.setTexture(textura);
            sprt.setPosition(cordenada);
            sprt.setScale(tamanho);
        }
        ~Entidade(){}
        Vector2f getSize(){
            return tamanho;
        }
        Vector2f getCordenada(){
            return cordenada;
        }
        Sprite getSprite(){
            return sprt;
        }
        void setposition(Vector2f paux){
            sprt.setPosition(paux);
        }
};

class Jogador : public Entidade{
    private:
        float vida;
        float dano;
        Vector2f velocidade;
        Vector2f vel_instantanea;
    public:
        Jogador(Vector2f coord, Vector2f tam, Texture txt, float vid, float dan, Vector2f vel) : Entidade(coord,tam,txt), vida(vid), dano(dan), velocidade(vel){}
        float get_Dano() const{return dano;}
        float get_Vida() const{return vida;}
        void set_vida(float vida_res){ vida = vida_res;}
        void setcord(Vector2f cordaux){
            cordenada = cordaux;
            setposition(cordenada);
        }
        const Vector2f get_velocidade() const{return velocidade;}
};


class Gerenciador_de_Eventos{
    private:
        Jogador* plr;
        Vector2f cord_jogador, vel_jogador;
    public:
        Gerenciador_de_Eventos(Jogador* plraux): plr(plraux){
            cord_jogador = plr->getCordenada();
            vel_jogador = plr->get_velocidade();
        }
        void gerenciar_input(){
            if(Keyboard::isKeyPressed(Keyboard::A)){
                cord_jogador.x -= vel_jogador.x; 
                plr->setcord(Vector2f(cord_jogador));
            }
            else if(Keyboard::isKeyPressed(Keyboard::D)){
                cord_jogador.x += vel_jogador.x; 
                plr->setcord(cord_jogador);
            }
            else if(Keyboard::isKeyPressed(Keyboard::S)){
                cord_jogador.y += vel_jogador.y; 
                plr->setcord(cord_jogador);
            }
            else if(Keyboard::isKeyPressed(Keyboard::W)){
                cord_jogador.y -= vel_jogador.y; 
                plr->setcord(cord_jogador);
            }
        }
};
*/
int main(){
    Principal objPrincipal;
    
}

/*sf::RenderWindow window(sf::VideoMode(600, 500), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    Texture txt, tchao, tfundo;
    tchao.loadFromFile("moon.png");
    txt.loadFromFile("default.png");
    tfundo.loadFromFile("moon_background.png");
    Jogador player(Vector2f(300.f, 400.f), Vector2f(1.f,1.f), txt, 5.0, 3.0, Vector2f(0.1,0.1));
    Entidade chao(Vector2f(0.f, 300.f), Vector2f(6.5f,6.5f), tchao);
    Entidade background(Vector2f(0.f, 50.f), Vector2f(6.f,10.f), tfundo);
    Gerenciador_de_Eventos gf(&player);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(chao.getSprite());
        window.draw(background.getSprite());
        window.draw(player.getSprite());
        window.display();
        gf.gerenciar_input();
    }
*/