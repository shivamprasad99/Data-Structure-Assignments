all: sample

sample: main.o entry.o dictionary.o
	g++ -std=c++14 main.o entry.o dictionary.o -o sample

main.o: main.cpp
	g++ -std=c++14 -c main.cpp

entry.o : entry.cpp
	g++ -std=c++14 -c entry.cpp

dictionary.o: dictionary.cpp
	g++ -std=c++14 -c dictionary.cpp

clean:
	rm *o sample