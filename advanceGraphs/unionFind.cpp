/* we will implement kruskals algorithm using union find algorithm */
/* union find algorithm is used to calculate weather an edge forms a cycle or not */
/* kruskals algo is used to find the mst */

#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
    int src;
    int dest;
    int weight;
};


/* this function will return the outermost parent */
int getParent(int* parent, int child){
    /* initially every vertex has a parent --> vertex itself */
    if(child == parent[child]){
        return child;
    }else{
        /* find the parent of child */
        return getParent(parent,parent[child]);
    }
}

edge* kruskals(edge* edges, int n, int m){
    edge* output = new edge[n-1];
    /* union find algorithm */
    int* parent = new int[n];
    /* initially it is assumed that each vertex is a separate connected component */
    /* so each component is a parent of itself */
    /* vertices are numbered from 0 to n-1 */
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    int count = 0;
    int i = 0;
    /* MST has only n-1 edges if there are n vertices in the graph */
    while(count < n-1){
        /* each edge contains one src and one dest */
        edge currentEdge = edges[i];
        int srcParent = getParent(parent,currentEdge.src);
        int destParent = getParent(parent,currentEdge.dest);
        /* if the parent of src and dest are different then we can say that */
        /* both the edges(src and dest) belongs to different component in the MST */
        /* and hence they are safe to join, as they will not form the cycle */
        if(srcParent != destParent){
            /* add the current edge into our output as a part of MST*/
            output[count++] = currentEdge;
            /* now parent for both src and dest will be same */
            /* we make parent of source vertex equal to parent of destinaton vertex */
            /* we make parent same so that now src and dest will be in a same group 
            having one common parent */
            parent[srcParent] = destParent;
        }
        i++;
    }
    delete [] parent;
    return output;
}

int main(){
    int n,m;
    cin >> n >> m;
    edge* edges = new edge[m];
    for(int i = 0; i < m; i++){
        int s,d,w;
        cin >> s >> d >> w;
        edges[i].src = s;
        edges[i].dest = d;
        edges[i].weight = w;
    }
    edge* output = kruskals(edges,n,m);
    /* print the output */
    cout << "------------ MST IS --------------" << endl;
    for(int i = 0; i < n-1; i++){
        if(output[i].src < output[i].dest){
            cout << output[i].src << " " << output[i].dest << " " << output[i].weight << endl;
        }else{
            cout << output[i].dest << " " << output[i].src << " " << output[i].weight << endl;
        }
    }
    delete [] output;
    delete [] edges;
    return 0;
}