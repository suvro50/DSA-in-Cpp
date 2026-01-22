#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void Dijkstra(int V, vector<vector<pair<int,int>>>& adj, int source) {
    // min-heap: {distance, node}
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    pq.push({0, source});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int currDist = top.first;
        int u = top.second;

        if (currDist > dist[u]) continue; // already found shorter path

        // explore neighbors
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    // Print shortest distances from source
    cout << "Vertex  Distance from source " << source << "\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\n";
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V); // adjacency list

    cout << "Enter edges (start_vertex end_vertex weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove this line if graph is directed
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    Dijkstra(V, adj, source);

    return 0;
}

// input
// 4 4
// 0 1 2
// 0 3 6
// 1 2 3
// 1 3 8
// 0