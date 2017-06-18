.DEFAULT_GOAL=compandrun
.PHONY: compandrun compile clean run

compile: main.cpp src/Prvok.cpp
	g++ -std=c++11 -c main.cpp -o main.o
	g++ -std=c++11 -c src/Prvok.cpp -o Prvok.o
	g++ -std=c++11 -c src/Grupa.cpp -o Grupa.o
	g++ -std=c++11 -c src/Iterator.cpp -o Iterator.o
	g++ -std=c++11 -c src/strategy/Algoritmus.cpp -o Algoritmus.o
	g++ -std=c++11 -c src/strategy/Bruteforce.cpp -o Bruteforce.o
	g++ -std=c++11 -c src/strategy/StrategyA.cpp -o StrategyA.o
	g++ -std=c++11 Prvok.o Grupa.o Iterator.o Algoritmus.o Bruteforce.o StrategyA.o main.o -o app

clean:
	rm -f main.o Prvok.o Grupa.o Algoritmus.o Bruteforce.o StrategyA.o Iterator.o

compandrun: compile clean run

run:
	./app
