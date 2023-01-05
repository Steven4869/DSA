// It's only applicable for Directed Acyclic Graph 
// Linear ordering of vertices such that for every edge u->v, u always comes before v 
// adj List:
// 1 -> 2, 3
// 2 -> 3
// 3 -> 
// TS : 1 2 3 
// Multiple ordering can exist following this logic 

// DFS is the way to go for 
// We need visited array 
// Additional data structure required is stack which is used to store the elements then print it 

#include <bits/stdc++.h>
using namespace std;

// v -> no of vertices and e -> no of edges 

void topSort(unordered_map<int, list<int>> &adjList, vector<int>&visited, stack<int>st, int node){
    // 1. Mark the node as viisted 
    visited[node]=1;
    // 2. Check its neighbours 
    for(auto neighbours:adjList[node]){
        if(!visited[neighbours]){
            topSort(adjList, visited, st, neighbours);
        }
    }
    // 3. Store the result in stack 
    st.push(node);
}
vector<int> TopologicalSort(vector<vector<int>>edges, int v, int e){
    // Creating Adjacenccy List 
    unordered_map<int, list<int>> adjList;
    for(int i=0;i<e;i++){
        // First elemet of edges vector
        int u = edges[i][0];
        // Second element of the edges vector 
        int v = edges[i][1];

        // Only valid for Directed Graphs so one side printing
        adjList[u].push_back(v);
    }
    // Calling DFS Topoligcal Sort for all the components 
    // Creating a visited array and intialising stack 
    vector<int>visited(v); // Vector of int with size v
    stack<int>st;

    for(int i=0;i<v;i++){
        // If the array is not visited then call the function
        if(!visited[i]){
            topSort(adjList, visited, stack, i);
        }
    }
    // For Printing the answer 
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}