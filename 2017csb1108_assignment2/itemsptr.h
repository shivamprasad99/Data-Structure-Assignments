#ifndef ITEMSPTR_H
#define ITEMSPTR_H
#include "items.h"

class itemsptr{
    public:
    items* g;
    int cal;
    itemsptr(){
        g=NULL;
    }
    itemsptr(items* f){
        g=f;
        cal=f->getCalories();   //stores calories of item
    }
    bool operator >(itemsptr x);

    bool operator ==(itemsptr x);
};

inline bool itemsptr::operator >(itemsptr x){
        return cal > x.g->getCalories();    //compares this->cal with new object calories
    }

inline bool itemsptr::operator ==(itemsptr x){
        return cal == x.g->getCalories();
    }

#endif