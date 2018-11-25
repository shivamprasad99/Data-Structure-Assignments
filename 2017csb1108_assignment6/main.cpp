#include "graph.hpp"
using namespace std;

int main(int argc, char *argv[]){
    string fn(argv[1]);
    ifstream fin;
    fin.open(fn);
    map<string,int> cities;
    int index=0;
    while(fin){
        string n1,n2;
        float dist;
        fin>>n1>>n2>>dist;
        if(!fin)
            break;
        if(cities.find(n1) == cities.end())
            cities.insert({n1,index++});
        if(cities.find(n2) == cities.end())
            cities.insert({n2,index++});
    }
    graph<string> gp(cities);
    fin.close();

    fin.open(fn);
    while(fin){
        string n1,n2;
        float dist;
        fin>>n1>>n2>>dist;
        if(!fin)
            break;
        gp.addvertex(n1,n2,dist);   
    }
    fin.close();

    int choice = 1;
    while(choice){
        cout<<"Enter :\n"<<"1. For finding the largest city\n"<<"2. For finding the shorteset route between two cities\n"<<"3. For finding the minimum number of hops between two cities\n";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"The largest area city is "<<gp.most_connected()<<endl;
                break;
            }
            case 2:{
                cout<<"Enter the source and destination to find shortest route\n";
                string source,destination;
                cin>>source>>destination;
                gp.shortest_route(source,destination);
                break;
            }
            case 3:{
                cout<<"Enter the source and destination to find minimum hops\n";
                string source,destination;
                cin>>source>>destination;
                gp.minimum_hops(source,destination);
                break;
            }
            default:{
                choice = 0;
                break;
            } 
        }
    }
}