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

        void bfs(int startVertex){
            vector<int> visited(adjList.size(), 0);
            queue<int> q;

            q.push(startVertex);
            visited[startVertex] = 1;

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                cout<<frontNode<<" ";

                for(auto i:adjList[frontNode]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i]=1;
                    }
                }
            }
        }

        void dfsHelper(int node, vector<int> &visited){
            cout<<node<<" "<<endl;
            visited[node]=1;

            for(auto i: adjList[node]){
                if(!visited[i]){
                    cout<<"Before calling "<<i<<endl;
                    dfsHelper(i, visited);
                    cout<<"After Calling "<<i<<endl;
                }
            }
        }
        void dfs(int startVertex){
            vector<int> visited(adjList.size(), 0);
            dfsHelper(startVertex, visited);
        }
    
};

int main(){
    Graph g;

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    
    g.printGraph();

    cout<<endl;

    cout<<"BFS Implementation ";
    g.bfs(0);
    cout<<endl;

    cout<<"DFS Implementation ";
    g.dfs(0);
    cout<<endl;

    return 0;
}