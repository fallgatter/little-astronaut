#include"..\include\Principal.h"

Principal::Principal() : janela(sf::VideoMode(800.0f, 600.0f), "little astronaut"){
    executar();
}

Principal::~Principal(){

}

void Principal::executar(){
    Ge = new Gerenciadores::Eventos();
    Ge->setWindow(&janela);
    while(janela.isOpen()){
        sf::Event event;
        Ge->gerenciarInput(event);
        while (janela.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                janela.close();
            if (event.type == sf::Event::Resized)
                std::cout << event.size.width << event.size.height << std::endl;
        }
        janela.display();
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