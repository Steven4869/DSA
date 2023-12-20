#include <bits/stdc++.h>
using namespace std;

class Graph
{
    private:
        unordered_map<int, list<int> > adjList;

    public:
        void addEdge(int u, int v){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        void printGraph(){
            for(const auto &entry:adjList){
                cout<<"Adjacency List of the vertex "<<entry.first<<":";
                for(int neighbor:entry.second){
                    cout<<neighbor<<" ";
                }
                cout<<"\n";
            }
        }
    
};

int main(){
    Graph g;

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    
    g.printGraph();

    return 0;
}