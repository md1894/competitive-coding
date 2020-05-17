/*
BOTTOM
Send Feedback
We will use the following (standard) definitions from graph theory. 
Let V be a non-empty and finite set, its elements being called vertices (or nodes). 
Let E be a subset of the Cartesian product V×V, its elements being called edges. 
Then G=(V,E) is called a directed graph.

Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that 
ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). 
Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, 
writing (v1→vn+1).

Here are some new definitions. A node v in a graph G=(V,E) is called a sink, 
if for every node w in G that is reachable from v, v is also reachable from w. 
The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. 
You have to calculate the bottom of certain graphs.
Input Specification
The input contains several test cases, each of which corresponds to a directed graph G. 
Each test case starts with an integer number v, denoting the number of vertices of G=(V,E) 
where the vertices will be identified by the integer numbers in the set V={1,…,v}. 
You may assume that 1≤v≤5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.
Output Specification
For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.
Sample Input
3 3
1 3 2 3 3 1
2 1
1 2
0
Sample Output
1 3
2
*/

#include<bits/stdc++.h>
using namespace std;

/* this dfs function will fill the component container with a SSC */
void dfs2(vector<int>* edges, int start, set<int>& visited, set<int>* component){
    visited.insert(start);
    for(int i = 0; i < edges[start].size(); i++){
        int adjacent = edges[start][i];
        if(visited.count(adjacent) == 0){
            dfs2(edges, adjacent, visited, component);
        }
    }
    component->insert(start);
}

/* this dfs function will fill fill the stack */
void dfs(vector<int>* edges, int start, set<int>& visited, stack<int>& finishedVertices){
    visited.insert(start);
    for(int i = 0; i < edges[start].size(); i++){
        int adjacent = edges[start][i];
        if(visited.count(adjacent) == 0){
            dfs(edges,adjacent,visited,finishedVertices);
        }
    }
    finishedVertices.push(start);
}


/* kosarajus algorithm */
set<set<int>*>* getStronglyConnectedComponents(vector<int>* adjList, 
            vector<int>* adjListT, int n, int e)
{
    set<int> visited;
    stack<int> finishedVertices;
    for (int i = 0; i < n; i++) {
		if (visited.count(i) == 0) {
			dfs(adjList, i, visited, finishedVertices);
		}
	}
    set<set<int>*>* output = new set<set<int>*>();
	visited.clear();
    while(finishedVertices.size() != 0){
        int element = finishedVertices.top();
        finishedVertices.pop();
        set<int>* component = new set<int>();
        if(visited.count(element) != 0){
            continue;
        }
        dfs2(adjListT, element, visited, component);
        output->insert(component);
    }
    return output;
}


void displayBottomOfGraph(vector<int>* adjList, 
            vector<int>* adjListT, int vertices, int edges)
{
    //calculate the strongly connected components
    set<set<int>*>* components;
    components = getStronglyConnectedComponents(adjList,adjListT, vertices, edges);
    /* this iterator will get set one by one */
    set<set<int>*>::iterator it = components->begin();
    /* in question we have to print the ans in ascending order */
    /* one by one we will insert answer into this finalAns set */
    set<int> finalAns;
    while(it != components->end()){
        /* current set iterator */
        set<int>* currentComponent = *it;
        set<int>::iterator it1 = currentComponent->begin();
        bool flag = true;
        while(it1 != currentComponent->end()){
            int element = *it1;
            /* for each element of the set we will check */
            /* it must not have any outgoing edge to the element of any other SSC*/
            /* SSC strongly connected component */
            for(int i = 0; i < adjList[element].size(); i++){
                int adjacent = adjList[element][i];
                if(currentComponent->count(adjacent) == 0){
                    /* if that element has a outgoing edge with element of other SSC */
                    /* flag will set to false */
                    flag = false;
                    break;
                }
            }
            if(flag == false)
                break;
            it1++;
        }
        if(flag){
            /* if there is no outgoing edge to the element of other SSC */
            /* that SSC will be the bottom of our graph */
            /* so each element will be added to finalAns set */
            it1 = currentComponent->begin();
            while(it1 != currentComponent->end()){
                int a = (int)*it1+1;
                finalAns.insert(a);
                it1++;
            }
        }

        it++;
    }
    for(auto it1 : finalAns){
        cout << it1 << " ";
    }

}

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    while(vertices != 0){
        vector<int>* adjList = new vector<int>[vertices];
        vector<int>* adjListT = new vector<int>[vertices];
        for(int i = 0; i < edges; i++){
            int x, y;
            cin >> x >> y;
            adjList[x-1].push_back(y-1);
            adjListT[y-1].push_back(x-1);
        }
        displayBottomOfGraph(adjList,adjListT,vertices,edges);
        cin >> vertices >> edges;
    }
	return 0;
}
