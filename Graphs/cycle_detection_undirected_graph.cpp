// To detect cylce we check if the node is visited and the node doesn't have it's subsequnt parent 
// In this we'll also have a parent array to see the nodes and thier parents 
// Using BFS
// 


#include<bits/stdc++.h>
using namespace std;

void AdjList(unordered_map<int,list<int>> &adjList, vector<pair<int,int>>edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

bool isCyclicDetect(unordered_map<int,list<int>> &adjList, vector<int> &visited, int node){
    // Make a parent visited array 
    vector<int>parent;
    // Mark it as visited in bith visited array 
    parent[node]=-1; // Since the node is not a parent of anyone intially
    visited[node]=1;
    // Intialising Queue 
    queue<int>q;
    q.push(node);

    // Running loop until queue is empty 
    while(!q.empty()){
        int front_node = q.front();
        // Popping the node
        q.pop();

        // Traversing its neighours
        for(auto neighbours:adjList[front_node]){
            // Condition for Cyclic 
            // If it has visited and neighbour is not the parent 
            if(visited[neighbours]==1 && neighbours!=parent[front_node]){
                return true;
            }
            // If not visited
            else if(!visited[neighbours]){
                q.push(neighbours);
                visited[neighbours]=1;
                parent[neighbours]=front_node;
            }
        }
    }
    return false;

}
string CycleDetection(int vertex, vector<pair<int,int>>edges){
    unordered_map<int,list<int>>adjList;
    vector<int>visited;

    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bool ans = isCyclicDetect(adjList,visited,i);
            if(ans ==1){
                cout<<"YES"<<endl;
            }
        }
    }
    cout<<"NO"<<endl;

}