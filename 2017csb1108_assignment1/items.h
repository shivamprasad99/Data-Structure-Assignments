#ifndef ITEMS_H
#define ITEMS_H
#include <bits/stdc++.h>
using namespace std;

class items{

protected:
    string type;
    int x;
    int y;
    long purchaseId;
    string purchaseTime;

public:
    items(string type,int x,int y,long purchaseId,time_t now){
        this->type=type;
        this->x=x;
        this->y=y;
        this->purchaseId=purchaseId;
        this->purchaseTime=ctime(&now);
    }
    
    items(){

    }

    virtual void print();

    virtual void update(string type,int x,int y,long purchaseId,time_t now);

    virtual int getPrice();

    virtual int getAmount();

    virtual int getCalories();

    virtual void updateAmount(int newAmount);

    int getPurchaseId();

    int getX();

    int getY();

    string getType();

};

#endif