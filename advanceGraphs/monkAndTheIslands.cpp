#include<bits/stdc++.h>
using namespace std;



int minBridge(vector<int>* edges, int n, int m){
    queue<int> pendingNodes;
    unordered_set<int> visited;
    /* to keep the track of level */
    int* level = new int[n];
    for(int i = 0; i < n; i++){
        level[i] = -1;
    }
    pendingNodes.push(0);
    level[0] = 0;
    visited.insert(0);
    while(pendingNodes.size() != 0){
        int parentElement = pendingNodes.front();
        pendingNodes.pop();
        if(parentElement == n-1){
            return level[parentElement];
        }
        for(int i = 0; i < edges[parentElement].size(); i++){
            int neighbor = edges[parentElement][i];
            if(visited.count(neighbor) == 0){
                pendingNodes.push(neighbor);
                visited.insert(neighbor);
                level[neighbor] = level[parentElement] + 1; 
            }
        }
    }
    int ans = level[n-1];
    delete [] level;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        /* n is for number of vertices and m is for number of edges */
        int n, m;
        cin >> n >> m;
        vector<int>* edges = new vector<int>[n];
        for(int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            edges[x-1].push_back(y-1);
            edges[y-1].push_back(x-1);
        }
        /* simple bfs it is */
        cout << minBridge(edges,n,m) << endl;
        delete [] edges;
    }
    return 0;
}