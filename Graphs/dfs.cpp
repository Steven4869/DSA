// Depth First Search 
// This includes travelling one node then another 
// Uses Recursion 

// Algortihm 
// 1. Store the node in component 
// 2. Make the visited node to be true 
// 3. For every connected node do the recursive call 

#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(unordered_map<int, list<int>> &adjList, vector<int, bool> &visited, vector<int> component, int node){
    component.push_back(node);
    visited[node]=true;
    for(auto neighbours:adjList[node]){
        if(!visited[neighbours]){
            dfs(adjList,visited,component, neighbours);
        }
    }

}

vector<int> DFS(int vertex, vector<pair<int,int>>edges){
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    vector<int, bool> visited;  

    // Preparing Adjacency List 
    prepareAdjList(adjList, edges);

    // Traversing the components of graph 
    for(int i=0;i<vertex.size();i++){
        if(!visited[i]){
            vector<int>component;
            dfs(adjList,visited, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}