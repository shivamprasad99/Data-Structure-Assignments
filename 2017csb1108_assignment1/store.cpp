#include "store.h"

// the ad functions are used to add new fruits or vegetables to the linkedlist(store a)
void store::add(string type,int x,int y,long purchaseId,time_t now,float weight,int price,int calories,int units){ //to add node in linkedlist 
        node* temp = new node();
        temp->next=NULL;
        temp->grocery = new fruits(type,x,y,purchaseId,now,weight,price,calories,units);
        *this + temp;
    }

void store::add(string type,int x,int y,long purchaseId,time_t now,int price,int volume,int calories,int amount){ //to add node in linkedlist
        node* temp = new node();
        temp->next = NULL;
        temp->grocery = new vegetables(type,x,y,purchaseId,now,price,volume,calories,amount);
        *this + temp;
    }

void store::sell(string type){                  //this asks the user which type of item they want
        cout<<"The following are available\n";
        if(this->list(type)==0)
            return;
        cout<<"Select the purchaseID of the item you want to buy\n";
        long sellId;
        cin>>sellId;
        node* temp=head;
        int minprice=INT_MAX,typecount=0,amount1;
        node* minindex;
        while(temp!=NULL){
            if(temp->grocery->getPurchaseId()==sellId){
                typecount++;
                minprice=temp->grocery->getPrice();
                amount1=temp->grocery->getAmount();
                minindex=temp;
            }
            temp=temp->next;
        }
        if(typecount==0){
            cout<<"The entered purchaseId is not available in the system\n";
            return;
        }
        else{
            int buy_amount;
            cout<<"The rate is "<<minprice<<" and amount is "<<amount1<<endl;;
            cout<<"Enter the amount you want to buy :"<<endl;
            cin>>buy_amount;
            while(buy_amount>amount1){
                cout<<"Your amount exceeds the reserves; enter again\n";
                cin>>buy_amount;
            }
            cout<<"Pay Rs."<<buy_amount*minprice<<endl;
            char c;
            cout<<"Do you want to proceed ? (y/n) ";
            cin>>c;
            if(c=='y'){
                minindex->grocery->updateAmount(amount1-buy_amount);
                if(amount1==buy_amount){
                    if(minindex==head){
                        node* zero=minindex;
                        head=head->next;
                        delete zero;
                    }
                    else{
                        node* zero=head;
                        while(zero->next!=minindex){
                            zero=zero->next;
                        }
                        node* waste=zero->next;
                        zero->next=zero->next->next;
                        delete waste;
                    }
                }
            }
            //minindex->grocery->update();
        }
    }

int store::list(string type){       //this function lists the entered item type and counts its total
        node* temp=head;
        int total=0;
        while(temp!=NULL){
            if(temp->grocery->getType()==type){
                temp->grocery->print();
                total+=temp->grocery->getAmount();
            }
            temp=temp->next;
        }
        cout<<"Total amount of "<<type<<" is "<<total<<endl;
        cout<<"--------------------------------------------\n";
        return total;
    }

void store::printList(){
        if(head==NULL)
            return;
        node* temp=head;
        while(temp!=NULL){
            temp->grocery->print();
            temp=temp->next;
        }
    }

void store::searchInArea(int x,int y,int x1,int y1){   //(x,y) for top-left and (x1,y1) for bottom-right
        node* temp=head;     //this node is to traverse the linked list and search the items available in a given area
        cout<<"\nThe following items are available in the given area\n";
        int itemcount=0;
        while(temp!=NULL){
            if(temp->grocery->getX() >= x && temp->grocery->getX() <= x1 && temp->grocery->getY() >= y1 && temp->grocery->getY() <= y){
                itemcount++;
                temp->grocery->print();
            }
            temp=temp->next;
        }
        if(itemcount==0)
            cout<<"Sorry! No items are available in the entered region.\n";
    }

void store::sellbyCalories(int calories){           //this function sells the items which has maximum number for the given number of calories
        node* temp=head;
        node* maxIndex=NULL;
        int maxAmount=0;
        while(temp!=NULL){
            if(calories/(temp->grocery->getCalories())>maxAmount && temp->grocery->getAmount() >= calories/(temp->grocery->getCalories())){
                maxAmount=calories/(temp->grocery->getCalories());
                maxIndex=temp;
            }
            if(temp->grocery->getAmount()*temp->grocery->getCalories() <= calories){
                if(temp->grocery->getAmount()>maxAmount){
                    maxAmount=temp->grocery->getAmount();
                    maxIndex=temp;
                }
            } 
            temp=temp->next;
        } 
        if(maxAmount==0){
            cout<<"You can't buy any single item for the given amount of calories\n";
            return;
        }
        cout<<"The maximum amount you can get is "<< maxAmount <<" of "<<maxIndex->grocery->getType()<< " and pay Rs."<<maxAmount*maxIndex->grocery->getPrice();
        maxIndex->grocery->updateAmount(maxIndex->grocery->getAmount()-maxAmount);
        if(maxIndex->grocery->getAmount()==0){
            if(maxIndex==head){
                    node* zero=maxIndex;
                    head=head->next;
                    delete zero;
                }
                else{
                    node* zero=head;
                    while(zero->next!=maxIndex){
                        zero=zero->next;
                    }
                    node* waste=zero->next;
                    zero->next=zero->next->next;                        
                    delete waste;
                }
        }
    }

void store::sellbyPrice(string type){           //this function is used to sell items of the entered type for the cheapest 
        int userAmount;
        cout<<"\nEnter the amount you want\n";
        cin>>userAmount;
        node* t=head;
        int total=0;
        while(t!=NULL){
            if(t->grocery->getType()==type){
                //temp->grocery->print();
                total+=t->grocery->getAmount();
            }
            t=t->next;
        }
        if(total<userAmount){
            cout<<"The entered amount is not available\n";
            return;
        }
        int buyAmount=0;
        while(userAmount!=0){
            node* temp=head;
            int minprice=INT_MAX,typecount=0,amount1;
            node* minindex;
            while(temp!=NULL){
                if(temp->grocery->getType()==type){
                    typecount++;
                    if(temp->grocery->getPrice()<minprice){
                        minprice=temp->grocery->getPrice();
                        amount1=temp->grocery->getAmount();
                        minindex=temp;
                    }
                }
                temp=temp->next;
            }
            if(userAmount<amount1){
                minindex->grocery->updateAmount(amount1-userAmount);
                buyAmount+=userAmount*minprice;
                userAmount=0;
            }
            else{
                userAmount=userAmount-amount1;
                buyAmount+=amount1*minprice;
                if(minindex==head){
                    node* zero=minindex;
                    head=head->next;
                    delete zero;
                }
                else{
                    node* zero=head;
                    while(zero->next!=minindex){
                        zero=zero->next;
                    }
                    node* waste=zero->next;
                    zero->next=zero->next->next;                        
                    delete waste;
                }
            }
        }
        cout<<"Pay Rs."<<buyAmount<<endl;
    }

template <typename T>
void store::operator+(T* temp){     // this overloaded + operator is used to add new fruit or vegetable to the beginning of linked list
        if(head==NULL){
            head=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
    }