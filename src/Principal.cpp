#include"..\include\Principal.h"
#include<math.h>
#include<vector>


Principal::Principal() : janela(sf::VideoMode(800.0f, 600.0f), "little astronaut"){
    Vw = new sf::View(sf::FloatRect(0.f, 0.f, 1000.f, 1000.f));
    //janela.setView(*Vw);
    Ge = new Gerenciadores::Eventos();
    Ge->setWindow(&janela);
    Ga.setWindow(&janela);
    Ga.setView(Vw);
    executar();
}

Principal::~Principal(){

}

void Principal::executar(){
    jogador = new Jogador(Vector2f(100.f,100.f));
    Texture txt, txt2;
    Sprite spr, spr2;
    vector<Inimigo*> inim;
    float i, quant = 4;
    Lista_Entidades listaux;
    Inimigo* enem;
    txt.loadFromFile("assets\\textures\\Player\\default.png");
    txt2.loadFromFile("assets\\textures\\Others\\gato.png");
    spr.setTexture(txt);
    spr2.setTexture(txt2);
    //for(i=0;i<quant;i++){
        enem = new Inimigo(100.f * i, 100.f);
        ent.EL.push(enem);
        ent.EL.push(jogador);
        enem->setSprite(spr2);
    //}
    //Obstaculo* obs = new Obstaculo(Vector2f(300.f,300.f));
    jogador->setSprite(spr);
    //obs->setSprite(spr2);
    //ent.incluir(jogador); isso aqui está dando erro n sei porque
    GC.setList(ent);
    while(janela.isOpen()){
        sf::Event event;
        while (janela.pollEvent(event))
        {
            Ge->gerenciarInput(&event);
        }
        Keyboard tecl;
        jogador->interacao(&tecl);
        jogador->desacelerar();
        jogador->mover_se();  //teste para ver se a lista esta funcionando
        Ga.drawn(enem->getSprite());
        Ga.setViewPos(Vector2f(jogador->getPos().x+200, 100));
        Ga.drawn(jogador->getSprite());
        enem->desacelerar();
        enem->mover_se();
        //Ga.drawn(obs->getSprite());
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
    }
    aqui
    jogador = new Jogador(Vector2f(0.f,0.f));
    Texture txt;
    Sprite spr;
    txt.loadFromFile("textures\\Player\\default.png");
    spr.setTexture(txt);
    jogador->setSprite(spr);
    GC.setList(ent);
    while(janela.isOpen()){
        sf::Event event;
        while (janela.pollEvent(event))
        {
            Ge->gerenciarInput(&event);
        }
        Keyboard tecl;
        jogador->interacao(&tecl);
        jogador->desacelerar();
        jogador->mover_se();  //teste para ver se a lista esta funcionando
        Ga.setViewPos(Vector2f(jogador->getPos().x+200, jogador->getPos().y-200));
        Ga.drawn(spr);
        janela.draw(spr);
        /*if(fabs(jogador.getPos().x-inimigo.getPos().x)<fabs(jogador.getTam().x/2+inimigo.getTam().x/2) && fabs(jogador.getPos().y-inimigo.getPos().y)<fabs(jogador.getTam().y/2+inimigo.getTam().y/2)){
            //jogador.setPos(jogador.getPos()-Vector2f(10,10));
            Vector2f vaux = jogador.getVel();
            vaux.x = -vaux.x/2 + 0.0001;
            vaux.y = -vaux.y/2 + 0.0001;
            jogador.setVel(vaux);
            vaux.x = -vaux.x - 0.0001;
            vaux.y = -vaux.y - 0.0001;
            inimigo.setVel(vaux);
        }
        GC.gerenciar();
        Ga.display();
        Ga.clear();
    }*/
    
    
