all: sample

sample: main.o lab.o lec.o
	g++ main.o lab.o lec.o -o sample

main.o: main.cpp
	g++ -std=c++14 -c main.cpp

lec.o: lec.cpp
	g++ -std=c++14 -c lec.cpp

lab.o: lab.cpp
	g++ -std=c++14 -c lab.cpp

clean:
	rm *o sample