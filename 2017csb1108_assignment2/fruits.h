#ifndef FRUITS_H
#define FRUITS_H
#include "items.h"

class fruits : public items{

private:
    float weight_unit;
    int price_unit;
    int calories;
    int units;

public:
    fruits(string type,int x,int y,long purchaseId,time_t now,float weight,int price,int calories,int units) : items(type,x,y,purchaseId,now){
        this->weight_unit=weight;
        this->price_unit=price;
        this->calories=calories;
        this->units=units;
    }

    fruits(){

    }
    void print();

    void update(string type,int x,int y,long purchaseId,time_t now,float weight,int price,int calories,int units);

    int getPrice();

    int getAmount();

    int getCalories() const;

    void updateAmount(int newAmount);

};

#endif