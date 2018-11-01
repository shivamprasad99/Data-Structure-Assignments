#ifndef VEGETABLES_H
#define VEGETABLES_H
#include "items.h"

class vegetables : public items{

private:
    int volume_kg;
    int price_kg;
    int calories;
    int amount_kg;

public:
    vegetables(string type,int x,int y,long purchaseId,time_t now,int price,int volume,int calories,int amount_kg) : items(type,x,y,purchaseId,now){
        this->volume_kg=volume;
        this->price_kg=price;
        this->calories=calories;
        this->amount_kg=amount_kg;
    }

    vegetables(){

    }

    void print();

    void update(string type,int x,int y,long purchaseId,time_t now,int price,int volume,int calories,int amount_kg);

    int getPrice();

    int getAmount();

    int getCalories();

    void updateAmount(int newAmount);

};

#endif
