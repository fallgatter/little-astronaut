//Cabeçalhos Próprios:
#include"../../../include/Entidades/Personagens/Jogador.h"
#include"../../../include/Gerenciadores/Gerenciador_Eventos.h"

namespace Entidades{
    namespace Personagens{
        Jogador::Jogador(Vector2f POS): 
            Personagem(5.0, 1.0, Vector2f(40.f, 48.f), POS, 'j'), energia(100), pontuacao(0)
        {
            Sprite sprtemp;
            text.loadFromFile("assets\\textures\\Player\\default.png");
            sprtemp.setTexture(text);
            setSprite(sprtemp);
        }

        Jogador::~Jogador(){
        }
        
        void Jogador::setEnerg(int ENERGIA){
            energia=ENERGIA;
        }

        int Jogador::getEnerg() const{
            return energia;
        }

        void Jogador::mover_se(){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && energia){
                vel.y += -0.2;
                energia--;
            }
            if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && energia<100){
                energia++;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                vel.x += 0.1;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                vel.x -= 0.2;
            }
        }

        void Jogador::colidir(Entidade* outro, Vector2f ds){
            if(outro->getId()=='b'){//objeto
                Vector2f posAux=getPos();  
                if(ds.x>ds.y){
                    if(getPos().x<outro->getPos().x)//colisão em x
                        posAux.x+=ds.x;
                    else
                        posAux.x-=ds.x;
                    setVel(Vector2f(0.f, getVel().y));
                }
                else{
                    if(getPos().y<outro->getPos().y)
                        posAux.y+=ds.y;
                    else
                        posAux.y-=ds.y;
                    setVel(Vector2f(getVel().x, 0.f));
                }
                setPos(posAux);
            }
            else if(outro->getId()=='a' || outro->getId()=='v'){//inimigos
                Vector2f vjog = outro->getVel(), voutro=getVel();
                if(pos.y  + 2> outro->getPos().y)  //talvez de merda nesse + 2
                    vida--;
                cout<<vida<<endl;
                if(vida < 0){
                    vivo = 0;
                }
                if(ds.x>ds.y){
                    if(outro->getPos().x<getPos().x){
                        vjog.x+=1;
                        voutro.x-=1;
                    }
                    else{
                        vjog.x-=1;
                        voutro.x+=1;
                    }
                }
                else{
                    if(outro->getPos().y<getPos().y){
                        vjog.y+=1;
                        voutro.y-=1;
                    }
                    else{
                        vjog.y-=1;
                        voutro.y+=1;
                    } 
                }
                setVel(vjog);
                outro->setVel(voutro);
            }
            else if(outro->getId()=='j'){//jogador

            }
            else if(outro->getId()=='p'){//projéti

            }
        }
    };
};