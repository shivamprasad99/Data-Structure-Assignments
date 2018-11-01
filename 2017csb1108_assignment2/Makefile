all: sample

sample: items.o fruits.o vegetables.o main.o
	g++  items.o fruits.o vegetables.o main.o -o sample

items.o: items.cpp
	g++ -std=c++14 -c items.cpp

fruits.o: fruits.cpp
	g++ -std=c++14 -c fruits.cpp

vegetables.o: vegetables.cpp
	g++ -std=c++14 -c vegetables.cpp

main.o: main.cpp
	g++ -std=c++14 -c main.cpp

clean:
	rm *o sample