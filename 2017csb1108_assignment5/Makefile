all: sample

sample: main.o
	g++ -std=c++14 main.o -o sample

main.o: main.cpp
	g++ -std=c++14 -c main.cpp

clean:
	rm *o sample a.out
