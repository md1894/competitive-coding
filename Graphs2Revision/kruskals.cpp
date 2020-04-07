// used to find the minimum spannig tree in the graph

#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int source;
    int dest;
    int weight;
};

int findParent(int* parent, int vertex){
    if(parent[vertex] == vertex){
        return vertex;
    }else{
        return findParent(parent, parent[vertex]);
    }
}

bool cmp_(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

void kruskals(Edge* input, int V, int E){
    int i=0, count = 0;
    int* parent = new int[V];
    Edge* output = new Edge[V-1];
    for(int i = 0; i < V; i++){
        parent[i] = i;
    }
    sort(input, input + E, cmp_);
    while(count != V-1){
        Edge currentEdge = input[i];
        int sourceParent = findParent(parent, currentEdge.source);
        int destParent = findParent(parent, currentEdge.dest);
        if(sourceParent != destParent){
            output[i] = currentEdge;
            parent[sourceParent] = destParent;
            count++;
        }
        i++;
    }
    cout << endl;
    for(int i = 0; i < V-1; i++){
        if(output[i].source < output[i].dest){
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        }else{
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
        }
    }
}


int main(){
    int V, E;
    cin >> V >>E;
    Edge* input = new Edge[E];
    for(int i = 0; i < E; i++){
        cin >> input[i].source;
        cin >> input[i].dest;
        cin >> input[i].weight;
    }

    kruskals(input, V, E);

    delete [] input;

    return 0;
}