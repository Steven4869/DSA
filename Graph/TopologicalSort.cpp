#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int V;
        unordered_map<int, list<int> > adjList;
    
    public:

        Graph(int vertices) : V(vertices), adjList(vertices){}

        void addEdge(int u, int v){
            adjList[u].push_back(v);
        }

        void topologicalSortUtil(int vertex, vector<int>&visited, stack<int>&st){
            visited[vertex]=1;
            for(int neighbor:adjList[vertex]){
                if(!visited[neighbor]){
                    topologicalSortUtil(neighbor, visited, st);
                }
            }
            st.push(vertex);
        }

        void topologicalSort(){
            vector<int> visited(V, 0);
            stack<int> st;

            for(int i=0;i<V;i++){
                if(!visited[i]){
                    topologicalSortUtil(i, visited, st);
                }
            }

            cout<<"Topological Sort: ";
            while(!st.empty()){
                cout<<st.top()<<" ";
                st.pop();
            }
            cout<<endl;
        }

};

int main(){
    Graph g(6);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;

}