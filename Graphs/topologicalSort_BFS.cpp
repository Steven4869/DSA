// Topological Sort using BFS
// It's termed as Khan's Algorithm 
// Steps :
// 1. Find Indegree of all nodes
// 2. Make queue and insert all 0 indegree nodes 
// 3. Perform BFS 
// 4. Lower the indegree for every value as we pop 

#include <bits/stdc++.h>
using namespace std;

vector<int> TopoSort(vector<vector<int>>edges, int v, int e){
    // Create Adjacency List
    unordered_map<int, list<int>> adjList;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        // Since it's a DAG only one side will be represnted 
        adjList[u].push_back(v);
    }

    queue<int>q;
    // Find the indegree of nodes 
    vector<int>indegree(v);
    // Traverse through the list
    for(auto i:adjList){
        // Traversing through the second of the list
        for(auto j:i.second){
            // If the indegree is 0
            if(indegree[i]==0){
                // Then push it into queue 
                q.push(i);
            }
        }
    }
    // Perform BFS 
    vector<int>ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);
        for(auto neighbours:adjList[front]){
            indegree[neighbours]--;
            if(indegree[neighbours]==0)
                q.push(neighbours);
        }
    }
    return ans;
}