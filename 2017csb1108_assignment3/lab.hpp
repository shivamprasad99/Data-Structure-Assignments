#ifndef LAB_HPP
#define LAB_HPP
#include <string>
#include <iostream>
using namespace std;

class lab{
private:
    string name;
    float area;
    int doors,x,y,computers;
public:
    lab();

    lab(string name,float area,int doors,int x,int y,int computers);

    float getArea() const;

    void print();

    string getName();

};

#endif