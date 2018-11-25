#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <bits/stdc++.h>
using namespace std;

template <typename U>
class vertex{
private:
    U value;
    int index;
    int numNeighbors;
public:
    U getValue(){
        return value;
    }
    int getIndex(){
        return index;
    }
    void setValue(U val){
        value = val;
    }
    void setIndex(int ind){
        index = ind;
    }
    void setNB(int nb){
        numNeighbors = nb;
    }
    int nb(){
        return numNeighbors;
    }
};

template <typename T>
class edge{
private:
    vertex<T> v1;
    vertex<T> v2;
public:
    list< vertex<T> > edgeData(){
        list< vertex<T> > temp;
        temp.push_back(v1);
        temp.push_back(v2);
        return edgeData;
    }
};

template <typename V>
class graph{

private:

vector < vector<float> > wmat;    //weighted matrix
map<V,int> vertices;
map<int,V> util;
int d;

int minDistance(float dist[],bool spSet[]){
    float min = FLT_MAX;
    int min_index;
    for(int v=0;v<d;v++){
        if(spSet[v] == false && dist[v]<=min){
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[],int j){
    if(parent[j]==-1)
        return;
    printPath(parent,parent[j]);
    cout<<util.find(j)->second<<"->";
}

void printSolution(float dist[],int parent[],int dest,int src){
    printPath(parent,dest);
    cout<<endl;
}

public:

graph(map<V,int> ver){
    vertices = ver;

    for(auto it = vertices.begin();it != vertices.end();++it){
        util.insert({it->second,it->first});
    }
    d = ver.size();
    for(int i=0;i<d;i++){
        vector<float> vt(d,0);
        vector<int> vt2(d,0);
        wmat.push_back(vt);
    }
}

void addvertex(V val1,V val2,float wt){ // adding vertices to the adjacency matrices
    auto it1 = vertices.find(val1);
    auto it2 = vertices.find(val2);
    int i1 = it1->second,i2 = it2->second;
    wmat[i1][i2]=wt;
    wmat[i2][i1]=wt;
}

V most_connected(){     // the node with the most number of edges will be returned
    int max = 0;
    auto mcv = vertices.begin();
    for(auto it = vertices.begin(); it != vertices.end(); ++it){
        int row = it->second;
        int sum = 0;
        for(int i=0;i<d;i++){
            if(wmat[row][i])
            sum += 1;
        }
        if(sum>max){
            max = sum;
            mcv = it;
        }
    }
    return mcv->first;
}     

void shortest_route(V source,V destination){
    float dist[d];
    bool spSet[d];
    int parent[d];
    for(int i=0;i<d;i++){
        parent[i] = -1;
        dist[i] = FLT_MAX;
        spSet[i] = false;
    }
    if(vertices.find(source) == vertices.end() || vertices.find(destination) == vertices.end()){
        cout<<"Wrong input\n";return;
    }
    int src = vertices.find(source)->second, dest = vertices.find(destination)->second; //to store indices
    dist[src] = 0;
    
    for(int count = 0;count < d-1;count++){
        int u = minDistance(dist,spSet);
        spSet[u] = true;
        for(int v=0;v<d;v++){
            if(!spSet[v] && wmat[u][v] && (dist[u] + wmat[u][v])< dist[v]){
                parent[v] = u;
                dist[v] = dist[u] + wmat[u][v];
            }
        }
    }
    cout<<"The minimum distance is "<<dist[dest]<<endl;
    cout<<"Route :\n";
    cout<<util.find(src)->second<<"->";
    printSolution(dist,parent,dest,src);
}

void minimum_hops(V source,V destination){
    float dist[d];
    bool spSet[d];
    int parent[d];
    for(int i=0;i<d;i++){
        parent[i] = -1;
        dist[i] = FLT_MAX;
        spSet[i] = false;
    }
    if(vertices.find(source) == vertices.end() || vertices.find(destination) == vertices.end()){
        cout<<"Wrong input\n";return;
    }
    int src = vertices.find(source)->second, dest = vertices.find(destination)->second; //to store indices
    dist[src] = 0;
    
    for(int count = 0;count < d-1;count++){
        int u = minDistance(dist,spSet);
        spSet[u] = true;
        for(int v=0;v<d;v++){
            if(!spSet[v] && wmat[u][v] && (dist[u] + wmat[u][v])< dist[v]){
                parent[v] = u;
                dist[v] = dist[u] + 1;
            }
        }
    }
    cout<<"The minimum number of hops is "<<dist[dest]<<endl;
    cout<<"Route :\n";
    cout<<util.find(src)->second<<"->";
    printSolution(dist,parent,dest,src);
}

};

#endif