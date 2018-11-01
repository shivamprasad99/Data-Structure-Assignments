#ifndef LEC_HPP
#define LEC_HPP
#include <string>
#include <iostream>
using namespace std;

class lec{
private:
    string name;
    float area;
    int doors,x,y,chairs;
public:
    lec();

    lec(string name,float area,int doors,int x,int y,int chairs);

    void print();

    int getChairs() const;

    string getName();

};

#endif