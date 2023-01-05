// We need to find out the shortest path in undirected graph 
// We'l be given a source and destination node 
// Our task is to bring the shortest path from one source node to destination node 
// We need visited and a parent array and Queue. 
// Algorithm 
// 1. Create an Adjacency List 
// 2. Perform BFS 
// 3. Prepare shortest path 

#include <bits/stdc++.h>
using namespace std;

vector<int>shortestPath(vector<pair<int,int>>edges, int n, int m, int s, int t){
    // Creating Adjacency List 
    unordered_map<int, list<int>>adjList;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        // Pushing the nodes 
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    // Performing BFS 
    vector<int>visited;
    vector<int>parent;
    queue<int>q;
    
    // Pushing the source node into queue, marking it as visited and parent as -1
    q.push(s);
    visited[s]=1;
    parent[s]=-1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbours:adjList[front]){
            if(!visited[neighbours]){
                visited[neighbours]=1;
                parent[neighbours]=front;
                q.push(neighbours);
            }
        }
    }

    // Preparing the shortest path 
    vector<int>ans;
    int currentNode = t;
    ans.push_back(t);
    while(currentNode != s){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}