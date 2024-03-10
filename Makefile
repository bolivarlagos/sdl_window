all:
	g++ -std=c++17 main.cpp -o main.o -lSDL2

clean:
	rm *.o