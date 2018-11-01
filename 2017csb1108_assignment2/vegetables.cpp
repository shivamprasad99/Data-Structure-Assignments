#include "vegetables.h"

void vegetables::print(){
        items::print();
        cout<<"VOLUME IN A KG : "<<this->volume_kg<<endl;
        cout<<"PRICE OF A KG : "<<this->price_kg<<endl;
        cout<<"CALORIES : "<<this->calories<<endl;
        cout<<"AMOUNT (IN KGS) : "<<this->amount_kg<<endl;
        cout<<"-------------------------------"<<endl;
    }

void vegetables::update(string type,int x,int y,long purchaseId,time_t now,int price,int volume,int calories,int amount_kg){
        items::update(type,x,y,purchaseId,now);
        this->volume_kg=volume;
        this->price_kg=price;
        this->calories=calories;
        this->amount_kg=amount_kg;
    }

int vegetables::getPrice(){
        return this->price_kg;
    }

int vegetables::getAmount(){
        return this->amount_kg;
    }

int vegetables::getCalories() const{
        return this->calories;
    }

void vegetables::updateAmount(int newAmount){
        this->amount_kg=newAmount;
    }