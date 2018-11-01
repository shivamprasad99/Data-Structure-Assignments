#include "store.h"

int main(){
    store a;
    time_t mytime;
    char str[100];
    int x,y,price,calories,volume,units,amount;       
    long purchaseId=1;
    float weight;

    FILE* fp=fopen("fruits.txt","r");        
    if(fp){
        while(!feof(fp)){
            int t=fscanf(fp,"%s %d %d %f %d %d %d",str,&x,&y,&weight,&price,&calories,&units);
            string type(str);
            mytime = time(0);
            a.add(type,x,y,purchaseId,mytime,weight,price,calories,units);
            purchaseId++;
            if(t==0)
                break;
        }
        fclose(fp);
    }

    FILE* fp1=fopen("vegetables.txt","r");
    if(fp1){
        while(!feof(fp1)){
            int t=fscanf(fp1,"%s %d %d %d %d %d %d",str,&x,&y,&price,&volume,&calories,&amount);
            string type(str);
            mytime = time(0);
            a.add(type,x,y,purchaseId,mytime,price,volume,calories,amount);
            purchaseId++;
            if(t==0)
                break;
        }
        fclose(fp1);
    }

    char userchoice='a';
    string type;
    int x1,y1,userCalories;
    while(1){
        cout<<"\n\nNow the user can input their choice : \nEnter"<<endl;
        cout<<"0 to clear the screen"<<endl;
        cout<<"1 to add fruit to system"<<endl;
        cout<<"2 to add vegetable to the system"<<endl;
        cout<<"3 to buy item of choice"<<endl;
        cout<<"4 to buy an item at cheapest price\n";
        cout<<"5 to find out the amount of a fruit/vegetable available"<<endl;
        cout<<"6 to find the items available in the entered area"<<endl;
        cout<<"7 to display the list of available items"<<endl;
        cout<<"8 to buy according to calories"<<endl;
        cout<<"9 to terminate"<<endl;
        cin>>userchoice;
        switch(userchoice){
            case '0':
                system("clear");
                break;
            case '1':                     // now the user can add a fruit type item in list
                cout<<"\nEnter the details of the fruit in space separated and the following order\n";
                cout<<"(type, location(x,y), weight per unit, price per unit, calories, units to add)\n";
                scanf("%s %d %d %f %d %d %d",str,&x,&y,&weight,&price,&calories,&units);
                type=str;
                mytime = time(0);
                a.add(type,x,y,purchaseId,mytime,weight,price,calories,units);
                purchaseId++;
                break;
            case '2':                     // now the user can add a vegetable type item in list
                cout<<"\nEnter the details of the vegetable in space separated and following order\n";
                cout<<"(type, location(x,y), price per kg, volume per kg, calories, amount to add (kg))\n";
                scanf("%s %d %d %d %d %d %d",str,&x,&y,&price,&volume,&calories,&amount);
                type=str;
                mytime = time(0);
                a.add(type,x,y,purchaseId,mytime,price,volume,calories,amount);
                purchaseId++;
                break;
            case '3':                    // now the user can buy the cheapest item of a certain type from list
                cout<<"\nEnter the type of item you want to buy (i.e fruit or vegetable name)\n";
                cin>>type;
                a.sell(type);
                break;
            case '4':
                cout<<"\nEnter the type of item you want to buy (i.e fruit or vegetable name)\n";
                cin>>type;
                a.sellbyPrice(type);
                break;
            case '5':                    //now the user can view the items of a certain type in the list
                cout<<"\nEnter the type of your fruit/vegetable\n";
                cin>>type;
                a.list(type);
                break;
            case '6':                   // now the user can search for items in a given area range
                cout<<"\nEnter the coordinates (x,y) of the top left corner\n";
                cin>>x>>y;
                cout<<"Enter the coordinates (x,y) of the bottom right corner\n";
                cin>>x1>>y1;
                a.searchInArea(x,y,x1,y1);
                break;
            case '7':                  // now the user can view the list
                cout<<endl;
                a.printList();
                break;
            case '8':
                cout<<"\nEnter the maximum amount of calories\n";
                cin>>userCalories;
                a.sellbyCalories(userCalories);
                break;
            case '9':
                return 0;
            default:
                return 0;
        }
    }
}