#ifndef SQUEUE_H
#define SQUEUE_H
#include "items.h"
#include "fruits.h"
#include "vegetables.h"

template <typename E>
class node{
    E data;
    node *prev,*next;
    template <typename T>
    friend class sQueue;
};

template <typename E>
  class sQueue{					      // an interface for a queue
    node<E> *first,*last;
    int t;  //for size
    deque<E> mq;   // this deque is to implement sliding window technique to maintain minimum of sQueue
  public:
    sQueue();
    int size() const;				      // number of items in queue
    bool empty() const;	
    const E& min();			      // is the queue empty?
    const E& front();	      // the front element
    void enqueue (const E& e);			      // enqueue element at rear
    void dequeue();		      // dequeue element at front
  };

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
        return (mq.front());
    return NULL;
}

template <typename E>
const E& sQueue<E>::front(){
    if(!empty())
        return (first->data);
    return NULL;
}

template <typename E>
void sQueue<E>::enqueue (const E& e){
    node<E> *temp=new node<E>;
    temp->data=e;
    temp->next=NULL;
    temp->prev=last;
    if(!empty()){
      last->next=temp;
      last=last->next;
    }
    if(empty()){
        last=temp;
        first=temp;
        this->mq.push_back(e);
    }
    else{
        E x;
        if(!mq.empty())
            x=mq.back();
        while(x>e && !mq.empty()){
          mq.pop_back();
          if(!mq.empty())
             x=mq.back();
        }
        this->mq.push_back(e);
    }
    t++;
}

template <typename E>
void sQueue<E>::dequeue(){
    if(!empty()){
        node<E> *temp=new node<E>;
        temp=first;
        first=first->next;
        if(temp->data==mq.front()){
            mq.pop_front();
        }
        delete temp;
        t--;
    }
}

#endif
