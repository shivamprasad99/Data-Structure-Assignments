#include "lec.hpp"

lec::lec(){
        name="";
        area=0.0;
        doors=0;
        x=0;y=0;
        chairs=0;
    }

lec::lec(string name,float area,int doors,int x,int y,int chairs){
        this->name=name;
        this->area=area;
        this->doors=doors;
        this->x=x;
        this->y=y;
        this->chairs=chairs;
    }

void lec::print(){
        cout<<"------------------------------------------------\n";
        cout<<"NAME : "<<this->name<<endl;
        cout<<"AREA : "<<this->area<<endl;
        cout<<"NUMBER OF DOORS : "<<this->doors<<endl;
        cout<<"LOCATION : "<<this->x<<","<<this->y<<endl;
        cout<<"NUMBER OF CHAIRS : "<<this->chairs<<endl;
        cout<<"------------------------------------------------\n";
    }
int lec::getChairs() const{
    return this->chairs;
}


string lec::getName(){
    return this->name;
}
