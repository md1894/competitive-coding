#include<bits/stdc++.h>
#include<climits>
using namespace std;


int minVertex_(int* weights, bool* visited, int V){
    int minVertex = -1;
    for(int i = 0; i < V; i++){
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int** edges, int V, int E){
    bool* visited = new bool[V];
    int* parent = new int[V];
    int* weights = new int[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }
    weights[0] = 0;
    parent[0] = -1;
    for(int i = 1; i < V; i++){
        weights[i] = INT_MAX;
        parent[i] = -1;
    }

    for(int i = 0; i < V; i++){
        int minVert = minVertex_(weights, visited, V);
        visited[minVert] = true;
        for(int j = 0; j < V; j++){
            if(!visited[j] && edges[minVert][j] != 0){
                if(weights[j] > edges[minVert][j]){
                    weights[j] = edges[minVert][j];
                    parent[j] = minVert;
                }
            }
        }
    }

    for(int i = 1; i < V; i++){
        if(i < parent[i]){
            cout << i << " " << parent[i] << " " << weights[i] << endl;
        }else{
            cout << parent[i] << " " << i << " " << weights[i] << endl;
        }
    }
}

int main(){
    int V, E;
    cin >> V >> E;
    int** edges = new int*[V];
    for(int i = 0; i < V; i++){
        edges[i] = new int[V];
        for(int j = 0; j < V; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < E; i++){
        int src, dest, weight;
        cin >> src >> dest >> weight;
        edges[src][dest] = weight;
        edges[dest][src] = weight;
    }

    prims(edges, V, E);
    return 0;
}