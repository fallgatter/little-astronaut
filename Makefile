all: compile link

compile:
	g++ -c main.cpp src/*.cpp src/Entidades/*.cpp src/Gerenciadores/*.cpp -I"C:\Users\Pedro Henrique\Desktop\Estudos\Bibliotecas\SFML-2.5.1\include" -DSFML_STATIC

link:
	g++ *.o -o main -L"C:\Users\Pedro Henrique\Desktop\Estudos\Bibliotecas\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

clean:
	del -f main *.o