#include"..\include\Principal.h"
#include<math.h>

Principal::Principal() : janela(sf::VideoMode(800.0f, 600.0f), "little astronaut"){
    Ge = new Gerenciadores::Eventos();
    Ge->setWindow(&janela);
    Ga.setWindow(&janela);
    executar();
}

Principal::~Principal(){

}

void Principal::executar(){
    Texture txt, txt2;
    txt.loadFromFile("textures\\Player\\default.png");
    Sprite sprt, sprt2;
    sprt.setTexture(txt);
    jogador.setSprite(sprt);
    jogador.setTam(Vector2f(40.0f, 48.0f));

    Inimigo inimigo;
    txt2.loadFromFile("textures\\Enemies\\green_alien.png");
    sprt2.setTexture(txt2);
    inimigo.setSprite(sprt2);
    inimigo.setPos(Vector2f(500.0f, 0.0f));
    inimigo.setTam(Vector2f(40.0f, 48.0f));

    //jogador.setPos(Vector2f(100.f,100.f));
    while(janela.isOpen()){
        sf::Event event;
        while (janela.pollEvent(event))
        {
            Ge->gerenciarInput(&event);
        }
        Keyboard tecl;
        jogador.interacao(&tecl);
        jogador.desacelerar();
        jogador.mover_se();
        Ga.drawn(jogador.getSprite());
        Ga.drawn(inimigo.getSprite());
        inimigo.mover_se();
        inimigo.desacelerar();
        if(fabs(jogador.getPos().x-inimigo.getPos().x)<fabs(jogador.getTam().x/2+inimigo.getTam().x/2) && fabs(jogador.getPos().y-inimigo.getPos().y)<fabs(jogador.getTam().y/2+inimigo.getTam().y/2)){
            jogador.setPos(jogador.getPos()-Vector2f(10,10));
        }
        
        Ga.display();
        Ga.clear();
    }
}

/*//Ge = new Gerenciadores::Eventos();
    //Ge->setWindow(&janela);
    while(janela.isOpen()){
        //Ge->gerenciarInput();
        sf::Event event;
        while (janela.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                janela.close();
            if (event.type == sf::Event::Resized)
                std::cout << event.size.width << event.size.height << std::endl;
        }
        janela.display();
    }*/