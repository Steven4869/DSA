// Basic display of Graph with Adjacency List 
#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
        // Declaration of Adjacency List
        unordered_map<int,list<int>> adjList;
        // Creating edges 
        void addEdge(int u, int v, bool direction){
            // If direction =0 => undirected 
            // If direction =1 => directed 
            adjList[u].push_back(v);
            if(direction==0){
                adjList[v].push_back(u);
            }
        }
        void printList(){
            for(auto i:adjList){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<" , ";
                }
                cout<<endl;
            }
        }
};

int main(){
    // Number of nodes 
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    // Number of edges
    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        // Creating an undirected Graph 
        g.addEdge(u,v,0);
    }
    // Printing Graph
    g.printList();
}