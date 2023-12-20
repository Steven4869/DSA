#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Graph data structure using adjacency list
class Graph {
    int V; // number of vertices
    vector<pair<int, int> > *adj; // pointer to adjacency list

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void dijkstra(int src);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w)); // for undirected graph
}

void Graph::dijkstra(int src) {
    // Create a priority queue to store vertices that are being processed
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    // Create a vector for distances and initialize all distances as infinite
    vector<int> dist(V, INT_MAX);

    // Insert source vertex into the priority queue and initialize its distance as 0
    pq.push(make_pair(0, src));
    dist[src] = 0;

    // Process vertices in the priority queue
    while (!pq.empty()) {
        int u = pq.top().second; // Extract minimum distance vertex from priority queue
        pq.pop();

        // Visit all adjacent vertices of the extracted vertex
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = i->first; // Get vertex label and weight of the current adjacent of u
            int weight = i->second;

            // If there is a shorter path to v through u, update the distance of v
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Print the distances of all vertices from the source vertex
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << endl;
}

int main() {
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.dijkstra(0);

    return 0;
}
