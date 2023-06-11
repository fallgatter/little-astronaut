//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Jogador.h"
#include"../../../include/Entidades/Obstaculos/Bandeira.h"
#include"../../../include/Entidades/Obstaculos/Bloco.h"
#include"../../../include/Entidades/Obstaculos/Espinho.h"
#include"../../../include/Entidades/Obstaculos/Meteoro.h"
#include"../../../include/Entidades/Projetil.h"

namespace Entidades{
    namespace Personagens{
        Jogador::Jogador(Vector2f POS, int ID): 
            Personagem(10, 2, true, Vector2f(40.f, 48.f), POS, ID), energia(100), pontuacao(0)
        {
            Sprite sprtemp;
            if(ID=='j')//Jogador 1
                text.loadFromFile("assets\\textures\\Players\\player1.png");
            else if(ID=='g'){//Jogador 2
                text.loadFromFile("assets\\textures\\Players\\player2.png");
            }
            sprtemp.setTexture(text);
            setSprite(sprtemp);
        }

        Jogador::~Jogador(){

        }
        
        void Jogador::setEnerg(int ENERGIA){
            energia=ENERGIA;
        }
        
        void Jogador::setPontuacao(int PONTOS){
            pontuacao+=PONTOS;
        }

        int Jogador::getEnerg() const{
            return energia;
        }

        int Jogador::getPontuacao() const{
            return pontuacao;
        }

        void Jogador::mover_se(){
            if(id=='j'){//Jogador 1
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && energia){
                    vel.y += -0.2;
                    energia--;
                }
                if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && energia<100){
                    energia++;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    vel.x += 0.2;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    vel.x -= 0.2;
                }
            }
            else if(id=='g'){//Jogador 2
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && energia){
                    vel.y += -0.2;
                    energia--;
                }
                if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && energia<100){
                    energia++;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                    vel.x += 0.2;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                    vel.x -= 0.2;
                }
            }
        }

        void Jogador::colidir(Entidade* outro, Vector2f ds){
            if(outro!=NULL){
                if(outro->getId() == 'm'){//meteoro
                    sofrerDano(static_cast<Meteoro*>(outro)->getDano());
                }
                else if(outro->getId() == 'e'){//espinho
                    if(vel.x != 0)//só sofre dano se estiver se movendo contra o espinho
                        if(rand()%70 == 1)
                            sofrerDano(static_cast<Espinho*>(outro)->getDano());
                        if(static_cast<Espinho*>(outro)->getRugoso()){
                            vel.x*=0.9;
                            vel.y*=0.9;
                        }
                }
                else if(outro->getId()=='b'){//bloco
                    Vector2f posAux=getPos();  
                    if(ds.x>ds.y){//colisão em x
                        if(getPos().x<outro->getPos().x)
                            posAux.x+=ds.x;
                        else
                            posAux.x-=ds.x;
                        vel.x=0.0;
                    }
                    else{//colisão em y
                        if(getPos().y<outro->getPos().y)
                            posAux.y+=ds.y;
                        else
                            posAux.y-=ds.y;
                        vel.y=0.0f;
                    }
                    if(static_cast<Bloco*>(outro)->getRugoso())
                        vel.x*=0.5;
                    setPos(posAux);
                }
                else if(outro->getId()=='f'){//bandeira
                    static_cast<Bandeira*>(outro)->setP1(1);
                }
                else if(outro->getId()=='a' || outro->getId()=='v' || outro->getId()=='c'){//inimigos
                    Vector2f vjog = outro->getVel(), voutro=getVel();
                    if(ds.x>ds.y){//colisão em x
                        if(outro->getPos().x<getPos().x){
                            vjog.x+=1.5;
                            voutro.x-=1.5;
                            sofrerDano(outro->getDano());
                        }
                        else{
                            vjog.x-=1.5;
                            voutro.x+=1.5;
                            sofrerDano(outro->getDano());
                        }
                    }
                    else{//colisão em y
                        if(outro->getPos().y<getPos().y){
                            vjog.y+=1.5;
                            voutro.y-=1.5;
                            sofrerDano(outro->getDano());
                        }
                        else{
                            vjog.y-=5;
                            voutro.y+=1.5;
                            static_cast<Personagem*>(outro)->sofrerDano(getDano());
                        } 
                    }
                    setVel(vjog);
                    outro->setVel(voutro);
                    if(!(outro->getVivo()) && outro->getId()=='c')//neutralizou o chefao (gato)
                        setPontuacao(1000);
                    else if(!(outro->getVivo()) && outro->getId()!='c')//neutralizou alien/OVNI
                        setPontuacao(100);
                }
                else if(outro->getId()=='p'){//projétil
                    sofrerDano(outro->getDano() * static_cast<Projetil*>(outro)->getCoef());
                    outro->setVivo(false);
                }
            }
        }   
    };
};