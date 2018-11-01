#include "items.h"

void items::print(){
        cout<<"\n\nTYPE : "<<this->type<<endl;
        cout<<"LOCATION : "<<this->x<<","<<this->y<<endl;
        cout<<"PURCHASE ID : "<<this->purchaseId<<endl;
        cout<<"PURCHASE TIME : "<<this->purchaseTime;
    }

void items::update(string type,int x,int y,long purchaseId,time_t now){
        this->type=type;
        this->x=x;
        this->y=y;
        this->purchaseId=purchaseId;
        this->purchaseTime=ctime(&now);
    }

int items::getPrice(){

    }

int items::getAmount(){}

int items::getCalories() const{}

string items::getType(){
    return this->type;
}

void items::updateAmount(int newAmount){}

int items::getPurchaseId(){
    return this->purchaseId;
}

int items::getX(){
    return this->x;
}

int items::getY(){
    return this->y;
}