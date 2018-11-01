#include "pQueue.hpp"
#include "lec.hpp"
#include "lab.hpp"
#include <fstream>
using namespace std;

class LabCompare
{
    public:
    bool operator()(const lab& lhs, const lab& rhs)
    {
        return lhs.getArea() < rhs.getArea();
    }
};

class LecCompare
{
    public:
    bool operator()(const lec& lhs, const lec& rhs)
    {
        return lhs.getChairs() < rhs.getChairs();
    }
};


int main(){
    ifstream finlab,finlec; 
    string name;
    float area;
    int x,y,chairs,computers,doors;
    finlab.open("lab.txt");
    finlec.open("lec.txt");
    vector<lab> labv;
    vector<lec> lecv;

    while(finlab){
        finlab>>name>>area>>doors>>x>>y>>computers;
        lab temp(name,area,doors,x,y,computers);
        labv.push_back(temp);
    }
    labv.pop_back();
    finlab.close();
    pQueue<lab,LabCompare> labpq(labv);
    cout<<"Lab Size "<<labpq.size()<<endl;

    while(finlec){
        finlec>>name>>area>>doors>>x>>y>>chairs;
        lec temp(name,area,doors,x,y,chairs);
        lecv.push_back(temp);
    }
    lecv.pop_back();
    finlec.close();
    pQueue<lec,LecCompare> lecpq(lecv);
    cout<<"Lec Size "<<lecpq.size()<<endl;

    int lastinsert;
    int c,choice;
    cout<<"Enter 1 to choose operations on lab pQueue and 2 for lec pQueue\n";
    cin>>c;
    while(c==1){
        cout<<"Enter\n1. To add get size\n2. To add new lab to pQueue\n3. To print the current minimum in pQueue\n4. To remove current minimum\n5. To remove item\n6. To replace item \n7. To print items\n0. To exit\n";
        cin>>choice;
        if(choice==1){
            cout<<"Size is currently "<<labpq.size()<<endl;
        } 
        else if(choice==2){
            cout<<"Enter the details of the new lab in order :name,area,doors,x,y,computers\n";
            cin>>name>>area>>doors>>x>>y>>computers;
            lab temp(name,area,doors,x,y,computers);
            lastinsert=labpq.insert(temp);
            cout<<"The new element is inserted at index"<<lastinsert;
        }
        else if(choice==3){
            lab t=labpq.min();
            t.print(); 
        }
        else if(choice==4){
            labpq.removeMin();
        }
        else if(choice==5){
            int remindex;
            cout<<"Enter the index of the element you want to remove\n";
            cin>>remindex;
            if(remindex<=labpq.size())
                labpq.remove(remindex);
            else
                cout<<"Index is out of bounds\n";
        }
        else if(choice==6){
            cout<<"Enter the details of the new lab in order :name,area,doors,x,y,computers\n";
            cin>>name>>area>>doors>>x>>y>>computers;      
            lab temp(name,area,doors,x,y,computers);
            cout<<"Enter the index of the lab you want to replace\n";
            int repindex;
            cin>>repindex;
            if(repindex<=labpq.size())
                labpq.replace(repindex,temp);
            else
                cout<<"Index is out of bounds\n";      
        }
        else if(choice==7){
            labpq.printHeap();
        }
        else
            break;
    }
 
 
    while(c==2){
        cout<<"Enter\n1. To add get size\n2. To add new lec to pQueue\n3. To print the current minimum in pQueue\n4. To remove current minimum\n5. To remove item\n6. To replace item \n7. To print items\n0. To exit\n";
        cin>>choice;
        if(choice==1){
            cout<<"Size is currently "<<lecpq.size()<<endl;
        } 
        else if(choice==2){
            cout<<"Enter the details of the new lec in order :name,area,doors,x,y,chairs\n";
            cin>>name>>area>>doors>>x>>y>>chairs;
            lec temp(name,area,doors,x,y,chairs);
            lastinsert=lecpq.insert(temp);
            cout<<"The new element is inserted at index"<<lastinsert;
        }
        else if(choice==3){
            lec t=lecpq.min();
            t.print(); 
        }
        else if(choice==4){
            lecpq.removeMin();
        }
        else if(choice==5){
            int remindex;
            cout<<"Enter the index of the element you want to remove\n";
            cin>>remindex;
            if(remindex<=lecpq.size())
                lecpq.remove(remindex);
            else
                cout<<"Index is out of bounds\n";
        }
        else if(choice==6){
            cout<<"Enter the details of the new lab in order :name,area,doors,x,y,chairs\n";
            cin>>name>>area>>doors>>x>>y>>chairs;      
            lec temp(name,area,doors,x,y,chairs);
            cout<<"Enter the index of the lab you want to replace\n";
            int repindex;
            cin>>repindex;
            if(repindex<=lecpq.size())
                lecpq.replace(repindex,temp);
            else
                cout<<"Index is out of bounds\n";      
        }
        else if(choice==7){
            lecpq.printHeap();
        }
        else
            break;
    }
}
