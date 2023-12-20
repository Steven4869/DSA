#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int V;
        unordered_map<int, list<int> >adjList;

    public:

        Graph(int vertices){
            V=vertices;
        }

        void addedge(int u, int v){
            adjList[u].push_back(v);
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

        // bool isCyclic(){
        //     vector<int>visited(V,0);
        //     vector<int>dfsVisited(V,0);

        // }

    
};

int main(){
    Graph g(8);

    g.addedge(1,2);
    g.addedge(2,4);
    g.addedge(2,3);
    g.addedge(4,5);
    g.addedge(5,6);
    g.addedge(6,4);
    g.addedge(3,7);
    g.addedge(3,8);
    g.addedge(8,7);

    g.printGraph();


}