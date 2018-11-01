#include "squeue.h"
#include "fruits.h"
#include "items.h"
#include "vegetables.h"
#include "itemsptr.h"

int main(){
    sQueue<itemsptr> sq;
    time_t mytime;
    char str[100];
    int x,y,price,calories,volume,units,amount;       
    long purchaseId=1;
    float weight;
    char a='1';

    while(a>='1' && a<='7'){
        cout<<"\n\nNow the user can input their choice : \nEnter"<<endl;
        cout<<"1 to add fruits and vegetables to sQueue from file"<<endl;
        cout<<"2 to enqueue a fruit of choice"<<endl;
        cout<<"3 to enqueue a vegetable of choice"<<endl;
        cout<<"4 to dequeue an item"<<endl;
        cout<<"5 to get size of sQueue"<<endl;
        cout<<"6 to get minimum of sQueue"<<endl;
        cout<<"7 to get front of sQueue"<<endl;

        cin>>a;
            if(a=='1'){
                FILE *fp1=fopen("fruits.txt","r"),*fp2=fopen("vegetables.txt","r");

                if(fp1){
                    while(!feof(fp1)){
                        int t=fscanf(fp1,"%s %d %d %f %d %d %d",str,&x,&y,&weight,&price,&calories,&units);
                        string type(str);
                        mytime = time(0);
                        items* f=new fruits(str,x,y,purchaseId,mytime,weight,price,calories,units);
                        itemsptr temp(f);
                        sq.enqueue(temp);
                        purchaseId++;
                        if(t==0)
                            break;
                    }
                    fclose(fp1);
                }

                if(fp2){
                    while(!feof(fp2)){
                        int t=fscanf(fp2,"%s %d %d %f %d %d %d",str,&x,&y,&weight,&price,&calories,&units);
                        string type(str);
                        mytime = time(0);
                        items* v=new vegetables(type,x,y,purchaseId,mytime,price,volume,calories,amount);
                        itemsptr temp(v);
                        sq.enqueue(temp);
                        purchaseId++;
                        if(t==0)
                            break;
                    }
                    fclose(fp2);
                }
            }
            else if(a=='2'){
                cout<<"\nEnter the details of the fruit in space separated and the following order\n";
                cout<<"(type, location(x,y), weight per unit, price per unit, calories, units to add)\n";
                scanf("%s %d %d %f %d %d %d",str,&x,&y,&weight,&price,&calories,&units);
                mytime = time(0);
                items* f=new fruits(str,x,y,purchaseId,mytime,weight,price,calories,units);
                itemsptr temp(f);
                sq.enqueue(temp);
                purchaseId++;
            }
            else if(a=='3'){
                cout<<"\nEnter the details of the vegetable in space separated and following order\n";
                cout<<"(type, location(x,y), price per kg, volume per kg, calories, amount to add (kg))\n";
                scanf("%s %d %d %d %d %d %d",str,&x,&y,&price,&volume,&calories,&amount);
                mytime = time(0);
                items* v=new vegetables(str,x,y,purchaseId,mytime,price,volume,calories,amount);
                itemsptr temp(v);
                sq.enqueue(temp);
                purchaseId++;
            }
            else if(a=='4'){
                sq.dequeue();
            }
            else if(a=='5'){
                cout<<sq.size();
            }
            else if(a=='6'){
                itemsptr temp=sq.min();
                temp.g->print();
            }
            else if(a=='7'){
                itemsptr temp=sq.front();
                temp.g->print();
            }
            else
                return 0;

    }

}
