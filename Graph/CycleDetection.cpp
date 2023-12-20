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

        bool isCyclicBFS(int sourceNode){
            vector<int>visited(adjList.size(), 0);
            vector<int>parent(adjList.size(), -1);
            visited[sourceNode] = 1;

            queue<int>q;
            q.push(sourceNode);

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                for(auto i:adjList[frontNode]){
                    if (!visited[i]) {
                    q.push(i);
                    visited[i] = 1;
                    parent[i] = frontNode;
                    } else if (i != parent[frontNode]) {
                    // Cycle exists
                    return true;
                    }
                }
            }
            return false;
        }

        bool isCycleDFSUtil(int node, vector<int> &visited, int parent){
            visited[node] = 1;

            for(auto neighbor:adjList[node]){
                if(!visited[neighbor]){
                    if(isCycleDFSUtil(neighbor, visited, node)){
                        return true;
                    }
                }
                else if(neighbor != parent){
                    return true;
                }
            }
            return false;
        }

        bool isCycleDFS(){
            vector<int> visited(adjList.size(), 0);
            
            for(const auto &entry:adjList){
                if(!visited[entry.first]){
                    if(isCycleDFSUtil(entry.first, visited, -1)){
                        return true;
                    }
                }
            }
            return false;

        }
    
};

int main(){
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    
    
    
    g.printGraph();

    cout<<"Cycle Detection: ";
    if (g.isCycleDFS()) {
        cout << "Cycle exists";
    } else {
        cout << "No cycle";
    }
    cout<<endl;

    return 0;
}