#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Graph {
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
    }

    void BellmanFord(int s) {
        vector<int> dist(V, numeric_limits<int>::max());
        dist[s] = 0;

        for (int i = 1; i <= V-1; i++) {
            for (auto edgeList : adj) {
                for (auto edge : edgeList) {
                    int u = edgeList - adj.begin();
                    int v = edge.first;
                    int w = edge.second;
                    if (dist[u] != numeric_limits<int>::max() && dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }

        for (auto edgeList : adj) {
            for (auto edge : edgeList) {
                int u = edgeList - adj.begin();
                int v = edge.first;
                int w = edge.second;
                if (dist[u] != numeric_limits<int>::max() && dist[u] + w < dist[v]) {
                    cout << "Graph contains negative weight cycle" << endl;
                    return;
                }
            }
        }

        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ", Distance: " << dist[i] << endl;
        }
    }

private:
    int V;
    vector<vector<pair<int, int>>> adj;
};

int main() {
    Graph g(5);

    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    g.BellmanFord(0);

    return 0;
}
