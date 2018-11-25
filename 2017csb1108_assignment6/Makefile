all: citymap

citymap: main.o
	g++ -std=c++14 main.o -o citymap

main.o: main.cpp
	g++ -std=c++14 -c main.cpp

clean:
	rm *o citymap a.out