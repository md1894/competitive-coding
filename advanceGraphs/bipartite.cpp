#include<bits/stdc++.h>
using namespace std;

/*
Defination -- >> 
    it is a special graph such that you can divide the vertex set into 2 disjoint sets such that
    1. each vertex belongs to excatly one of the two sets
    2. each edge connects vertices of 2 different set

    note --> there must NOT present a single edge which connects vertices of the same set 
*/

bool bipartite(vector<int>* edges, int n, int m){
    queue<int> pendingNodes;
    /* we will toggle these two sets alternately */
    unordered_set<int> sets[2];
    /* initially we put the first node in the 0th set */
    sets[0].insert(0);
    /* as neighbor of the vertex 0 is pending so 0 is the pending node */
    pendingNodes.push(0);
    while(pendingNodes.size() != 0){
        /* for each pending node  */
        int element = pendingNodes.front();
        pendingNodes.pop();
        int currentSet = sets[0].count(element) == 1 ? 0 : 1;
        /* iterate through the neighbor of element */
        for(int i = 0; i < edges[element].size(); i++){
            int neighbor = edges[element][i];
            if(sets[0].count(neighbor) == 0 && sets[1].count(neighbor) == 0){
                // put its neighbor in the set complement to current set
                sets[1-currentSet].insert(neighbor);
                pendingNodes.push(neighbor);
            }else if(sets[currentSet].count(neighbor) == 1){
                /* neighbor is present in the same set where element is present */
                return false;
            }
        }
    }
    return true;
}

int main(){
    /* n --> vertices m --> edges */
    int n, m;
    cin >> n >> m;
    vector<int>* edges = new vector<int>[n];
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        edges[x-1].push_back(y-1);
        edges[y-1].push_back(x-1);
    }
    bool ans = bipartite(edges,n,m);
    if(ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    delete [] edges;
    return 0;
}