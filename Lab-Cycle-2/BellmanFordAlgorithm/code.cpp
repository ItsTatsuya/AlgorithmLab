#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Structure to represent an edge from u to v with weight w.
struct Edge {
    int u, v;
    int w;
};

// Structure to represent a graph as an edge list.
struct Graph {
    int V, E;
    vector<Edge> edges;

    // Function to add an edge to the graph.
    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }
};

// Utility function to initialize the distances and predecessor array
void InitializeSingleSource(Graph &g, vector<int> &dist, vector<int> &pred, int source){
    dist.resize(g.V, numeric_limits<int>::max());
    pred.resize(g.V, -1);
    dist[source] = 0;
}

// Utility function to relax the edge if a shorter path is found.
void Relax(int u, int v, int weight, vector<int> &dist, vector<int> &pred){
    if(dist[v] > dist[u] + weight){
        dist[v] = dist[u] + weight;
        pred[v] = u;
    }
}

// The Bellman-Ford algorithm to find the single source shortest path in a graph with negative weight edges.
bool BellmanFord(Graph &g, int source, vector<int> &dist, vector<int> &pred) {
    InitializeSingleSource(g, dist, pred, source);

    for (int i = 1; i < g.V; ++i) {
        for (auto &edge: g.edges) {
            Relax(edge.u, edge.v, edge.w, dist, pred);
        }
    }

    // Check for negative-weight cycles.
    for (auto &edge: g.edges) {
        if (dist[edge.v] > dist[edge.u] + edge.w) {
            return false; // Negative-weight cycle found.
        }
    }

    return true; // No negative-weight cycles found.
}

// Utility function to print the shortest path from the source to a vertex v.
void PrintPath(const vector<int>& pred, int v) {
    if (v < 0) {
        return;
    }
    PrintPath(pred, pred[v]);
    if (pred[v] >= 0) {
        cout << " -> ";
    }
    cout << v;
}

int main() {
    Graph g;
    g.V = 5; // Number of vertices
    g.E = 8; // Number of edges

    // Adding edges.
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    vector<int> dist, pred;
    int source = 0;  // Starting node for BellmanFord.

    if (BellmanFord(g, source, dist, pred)) {
        cout << "Vertex   Distance from Source   Path" << endl;
        for (int v = 0; v < g.V; v++) {
            cout << v << "\t\t" << dist[v] << "\t\t\t";
            PrintPath(pred, v);
            cout << endl;
        }
    } else {
        cout << "Graph contains a negative-weight cycle" << endl;
    }

    return 0;
}