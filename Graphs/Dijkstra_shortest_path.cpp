// Dijkstra's algorithm 
// used to find the shortest path from source node to all other neighbours 
// Here weighted graphs will come into picture
// We need to find the shortest distance between each node from the source node 
// Approach 
// 1. Create a distance array afnd mark everyone as INFINTY, then make the source node as 0
// 2. Use either Set or Prirority Queue to get the shortest nodes 
// 3. Take the top value from the set and update the distance array 

#include<bits/stdc++.h>
using namespace std;

vector<int>dijkstra(vector<vector<int>> vec, int vertices, int edges, int source){
    // Create Adjacency List 
    unordered_map<int, list<int>>adjList;
    for(int i=0;i<vertices;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }

    // Creating distance array 
    vector<int>dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }

    // Creating pair to store the (ditance,node)pair 
    set<pair<int,int>>st;
    //  Make distance of source node to be zero and add it in the set 
    dist[source]=0;
    st.insert(make_pair(0,source));

    // Run the loop until the set becomes empty 
    while (!st.empty())
    {
        // Take out the top node 
        auto top = *(st.begin());
        // There are two things in the set 
        int nodeDistance = top.first;
        int topNode = top.second;

        // Remove the top record now 
        st.erase(st.begin());

        // Traverse the neighbours 

        for(auto neighbours:adjList[topNode]){
            // Compare the nodeDistance and neghbour node diatnce with distance array 
            if(nodeDistance+neighbours.second < dist[neighbours.first]){
                // Then update the record 
                auto record = st.find(make_pair(dist[neighbours.first],neighbours.first));

                // If the record is found then erase it from set 
                if(record!=st.end()){
                    st.erase(f);
                }
                // update the distance 
                dist[neighbours.first] = nodeDistance+neighbours.second;
                // Push the record into the set 
                st.insert(make_pair(dist[neighbours.first],neighbours.first));
            }
        }
    }
    // Return the distance array 
    return dist;
     
}