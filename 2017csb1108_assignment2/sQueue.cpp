#include "squeue.h"

template <typename E>
sQueue<E>::sQueue(){
    first=NULL;
    last=NULL;
    t=0;
}

template <typename E>
int sQueue<E>::size() const{
    return t;
}

template <typename E>
bool sQueue<E>::empty() const{
    return t==0;
}

template <typename E>
const E& sQueue<E>::min(){
    if(!empty())
        return &(mq.front());
    return NULL;
}

template <typename E>
const E& sQueue<E>::front(){
    if(!empty())
        return &(first->data);
    return NULL;
}

template <typename E>
void sQueue<E>::enqueue (const E& e){
    t++;
    node<E> *temp;
    temp->data=e;
    temp->next=NULL;
    temp->prev=last;
    last=temp;
    if(empty()){
        first=temp;
        mq.push_back(e);
    }
    else{
        while(mq.back()>e){
            mq.pop_back();
        }
        mq.push_back(e);
    }
}

template <typename E>
void sQueue<E>::dequeue(){
    t--;
    if(!empty()){
        node<E> *temp=first;
        first=first->next;
        if(temp->data==mq.front())
            mq.pop_front();
        delete temp;
    }
}