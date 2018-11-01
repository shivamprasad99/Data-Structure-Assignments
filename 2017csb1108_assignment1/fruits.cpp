#include "fruits.h"

void fruits::print(){
        items::print();
        cout<<"WEIGHT OF UNIT : "<<this->weight_unit<<endl;
        cout<<"PRICE OF A UNIT : "<<this->price_unit<<endl;
        cout<<"CALORIES : "<<this->calories<<endl;
        cout<<"NUMBER OF UNITS : "<<this->units<<endl;
        cout<<"-------------------------------"<<endl;
    }

void fruits::update(string type,int x,int y,long purchaseId,time_t now,float weight,int price,int calories,int units){
        items::update(type,x,y,purchaseId,now);
        this->weight_unit=weight;
        this->price_unit=price;
        this->calories=calories;
        this->units=units;
    }

int fruits::getPrice(){
        return this->price_unit;
    }

int fruits::getAmount(){
        return this->units;
    }

void fruits::updateAmount(int newAmount){
        this->units=newAmount;
    }

int fruits::getCalories(){
        return this->calories;
    }