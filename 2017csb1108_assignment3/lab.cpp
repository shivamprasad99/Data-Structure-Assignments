#include "lab.hpp"

lab::lab(){
        name="";
        area=0.0;
        doors=0;
        x=0;y=0;
        computers=0;
    }

lab::lab(string name,float area,int doors,int x,int y,int computers){
        this->name=name;
        this->area=area;
        this->doors=doors;
        this->x=x;
        this->y=y;
        this->computers=computers;
    }

void lab::print(){
        cout<<"------------------------------------------------\n";
        cout<<"NAME : "<<this->name<<endl;
        cout<<"AREA : "<<(float)this->area<<endl;
        cout<<"NUMBER OF DOORS : "<<this->doors<<endl;
        cout<<"LOCATION : "<<this->x<<","<<this->y<<endl;
        cout<<"NUMBER OF COMPUTERS : "<<this->computers<<endl;
        cout<<"------------------------------------------------\n";
    }

float lab::getArea() const{
    return this->area;
}

string lab::getName(){
    return this->name;
}
