// Breadth First Search Traversal
// Traverse the horixontal line first then goes down to check other line of horizontal nodes
// Uses Queue as data structure
// An Visited array is required to keep track of all the elements visisted in traversal

// Algorithm
// 1. Intialise the Queue
// 2. Push the node into Queue
// 3. Mark it as visited
// 4. Run the loop until all the elements are emoty
// 5. Intialise the front node to get the first element of the queue
// 6. Pop it and store node in the array
// 7. Traverse the neighbours of adjacency list of the first node (which will be keep on changing with each iteration)
// 8. If the node is not visited then push it into queue and mark it as visited

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

void bfs(unordered_map<int, list<int>> &adjList, vector<int, bool> &visited, vector<int> ans, int node){
    queue<int>q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto neighbours:adjList[frontNode]){
            if(!visited[neighbours]){
                q.push(neighbours);
                visited[neighbours]=1;
            }
        }
    }

}

vector<int> BFS(int vertex, vector<pair<int,int>>edges){
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    vector<int, bool> visited;  

    // Preparing Adjacency List 
    prepareAdjList(adjList, edges);

    // Traversing the components of graph 
    for(int i=0;i<vertex.size();i++){
        if(!visited[i]){
            bfs(adjList, visited, ans, i)
        }
    }
    return ans;
}