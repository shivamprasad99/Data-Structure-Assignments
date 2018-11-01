all: sample

sample: main.o store.o items.o fruits.o vegetables.o
	g++ main.o store.o items.o fruits.o vegetables.o -o sample

main.o: main.cpp
	g++ -c main.cpp

store.o: store.cpp
	g++ -c store.cpp

items.o: items.cpp
	g++ -c items.cpp

fruits.o: fruits.cpp
	g++ -c fruits.cpp

vegetables.o: vegetables.cpp
	g++ -c vegetables.cpp

clean:
	rm *o sample