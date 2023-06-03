#include"..\include\Principal.h"
#include<math.h>
#include<vector>


Principal::Principal() : janela(sf::VideoMode(800.0f, 600.0f), "little astronaut"){
     Vw = new sf::View(sf::FloatRect(0.f, 0.f, 1000.f, 1000.f));
    janela.setView(*Vw);
    Ge = new Gerenciadores::Eventos();
    Ge->setWindow(&janela);
    Ga = Ga->Singleton();
    Ga->setWindow(&janela);
    Ga->setView(Vw);
     executar();
}

Principal::~Principal(){
    delete(Ge);
}

void Principal::executar(){
    srand(time(NULL));
    moon.criarMapa();
    moon.setGrafico(Ga);
    moon.executar();
    }
    //Personagem:
    /*jogador = new Jogador(Vector2f(0.f,100.f));
    

    //Inimigos:
    int quant_inim=5;
    Inimigo* enem;
    vector<Inimigo*> inim;
    for(int i=0; i<quant_inim; i++){
        enem = new Inimigo(Vector2f(100.f * (i+1), 100.f));
        inim.push_back(enem);
        ent.EL.push(inim[i]);
    }
    
    //Obstaculos:
    int quant_obs=15;
    Obstaculo* obs;
    vector<Obstaculo*> obsts;

    for(int i=0; i<quant_obs; i++){
        obs = new Obstaculo(Vector2f(48.f * (i), 300.f), rand()%11);
        obsts.push_back(obs);
        ent.EL.push(obsts[i]);
    }
    /*moon.criarMapa();
    moon.executar();*/
    /*ent.EL.push(jogador);
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
        Ga.setViewPos(Vector2f(jogador->getPos().x+200, 100));
        Ga.drawn(jogador->getSprite());
        for(int i=0;i<quant_inim;i++){
            Ga.drawn(inim[i]->getSprite());
            inim[i]->desacelerar();
            inim[i]->mover_se();
        }
        for(int i=0;i<quant_obs;i++){
            Ga.drawn(obsts[i]->getSprite());
        }
        GC.gerenciar();
        Ga.display();
        Ga.clear();
    }
}*/
/*void Principal::executar(){
    //jogador = new Jogador(Vector2f(0.f,0.f));
    jogador=new Jogador();
    
    Texture txt, txt2;
    Sprite spr, spr2;
    vector<Inimigo*> inim;
    float i, quant = 4;
    Lista_Entidades listaux;
    Inimigo* enem;//*enem1, *enem2;
    txt.loadFromFile("assets\\textures\\Player\\default.png");
    txt2.loadFromFile("assets\\textures\\Others\\gato.png");
    spr.setTexture(txt);
    spr2.setTexture(txt2);
    for(i=0;i<quant;i++){
        enem = new Inimigo(Vector2f(100.f * (i+1), 100.f));
        enem->setSprite(spr2);
        inim.push_back(enem);
        ent.EL.push(inim[i]);
    }
    ent.EL.push(jogador);/*
    enem1 = new Inimigo(Vector2f(0.f,0.f));
    enem1->setSprite(spr2);
    enem1->setPos(Vector2f(200.0f,0.f));
    *//*
    jogador->setPos(Vector2f(0.f,100.f));/*
    enem2 = new Inimigo(Vector2f(0.f,0.f));*/
    // enem2->setSprite(spr2);
    // ent.EL.push(enem2);
    // ent.EL.push(enem1);
    //Obstaculo* obs = new Obstaculo(Vector2f(300.f,300.f));
    /*jogador->setSprite(spr);
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
        Ga.setViewPos(Vector2f(jogador->getPos().x+200, 100));
        Ga.drawn(jogador->getSprite());
        for(i=0;i<quant;i++){
            Ga.drawn(inim[i]->getSprite());
            inim[i]->desacelerar();
            inim[i]->mover_se();
        }
        Ga.drawn(enem1->getSprite());
            enem1->desacelerar();
            enem1->mover_se();
            Ga.drawn(enem2->getSprite());
            enem2->desacelerar();
            enem2->mover_se();*/
        /*Ga.drawn(inim[0]->getSprite());
        inim[0]->desacelerar();
        inim[0]->mover_se();
        Ga.drawn(inim[1]->getSprite());
        inim[1]->desacelerar();
        inim[1]->mover_se();*/
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
        }*//*
        GC.gerenciar();
        Ga.display();
        Ga.clear();
    }
}*/

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
    
    
