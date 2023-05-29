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
    Texture txt, txt2, txt3;
    txt.loadFromFile("textures\\Player\\default.png");
    txt3.loadFromFile("textures\\Enemies\\ufo.png");
    Sprite sprt, sprt2, sprt3;
    sprt3.setTexture(txt3);
    sprt.setTexture(txt);
    jogador.setSprite(sprt);
    jogador.setTam(Vector2f(40.0f, 48.0f));
    jogador.setId('j');
    Inimigo inimigo, inimigo2;
    Obstaculo obs;
    obs.setTam(Vector2f(100.0f, 100.0f));
    obs.setSprite(sprt3);
    inimigo.setId('i');
    inimigo.setId('i');
    txt2.loadFromFile("textures\\Enemies\\green_alien.png");
    sprt2.setTexture(txt2);
    inimigo.setSprite(sprt2);
    inimigo2.setSprite(sprt2);
    inimigo.setPos(Vector2f(300.0f, 0.0f));
    inimigo.setTam(Vector2f(40.0f, 48.0f));
    inimigo2.setPos(Vector2f(400.0f, 0.0f));
    inimigo2.setTam(Vector2f(40.0f, 48.0f));
    ent.EL.push(&inimigo);
    ent.EL.push(&jogador);
    ent.EL.push(&inimigo2);
    obs.setPos(Vector2f(0.0f,400.0f));
    ent.EL.push(&obs);
    jogador.setPos(Vector2f(200.f,200.f));
    GC.setList(ent);
    printf("funcionaprintf\n");
    int i=ent.EL.get_size();
    while(janela.isOpen()){
        sf::Event event;
        while (janela.pollEvent(event))
        {
            Ge->gerenciarInput(&event);
        }
        Keyboard tecl;
        jogador.interacao(&tecl);
        jogador.desacelerar();
        jogador.mover_se();  //teste para ver se a lista esta funcionando
        Ga.drawn(jogador.getSprite());
        Ga.drawn(inimigo.getSprite());
        Ga.drawn(obs.getSprite());
        Ga.drawn(inimigo2.getSprite());
        inimigo.mover_se();
        inimigo.desacelerar();
        inimigo2.mover_se();
        inimigo2.desacelerar();
        /*if(fabs(jogador.getPos().x-inimigo.getPos().x)<fabs(jogador.getTam().x/2+inimigo.getTam().x/2) && fabs(jogador.getPos().y-inimigo.getPos().y)<fabs(jogador.getTam().y/2+inimigo.getTam().y/2)){
            //jogador.setPos(jogador.getPos()-Vector2f(10,10));
            Vector2f vaux = jogador.getVel();
            vaux.x = -vaux.x/2 + 0.0001;
            vaux.y = -vaux.y/2 + 0.0001;
            jogador.setVel(vaux);
            vaux.x = -vaux.x - 0.0001;
            vaux.y = -vaux.y - 0.0001;
            inimigo.setVel(vaux);
        }*/
        inimigo.testemov();
        GC.gerenciar();
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