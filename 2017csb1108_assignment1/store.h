#ifndef STORE_H
#define STORE_H
#include "fruits.h"
#include "vegetables.h"

class node{
    items* grocery;
    struct node *next;
    friend class store;
};

class store{
private:
    node* head;

public:
    store(){
        head=NULL;
    }
    
    void add(string type,int x,int y,long purchaseId,time_t now,float weight,int price,int calories,int units);

    void add(string type,int x,int y,long purchaseId,time_t now,int price,int volume,int calories,int amount);

    void sell(string type);

    int list(string type);

    void printList();

    void searchInArea(int x,int y,int x1,int y1);

    void sellbyCalories(int calories);

    void sellbyPrice(string type);

    template <typename T>
    void operator + (T* temp);

};

#endif

