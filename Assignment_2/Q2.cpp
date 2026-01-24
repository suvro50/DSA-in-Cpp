#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;


void Dijkstra(int V, vector<vector<pair<int,int>>>& adj, int source, vector<int>& dist, vector<int>& parent) {
    dist.assign(V, INT_MAX); 
    parent.assign(V, -1);
    
    dist[source] = 0;

    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int currDist = top.first;
        int u = top.second;

        if (currDist > dist[u]) continue; 

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }
}

void printPath(int s, int t, int k, vector<int>& dist_s, vector<int>& parent_s, vector<int>& dist_k, vector<int>& parent_k) {
    
    if (dist_s[k] == INT_MAX || dist_k[t] == INT_MAX) {
        cout << "No valid path" << endl;
        return;
    }

    int total = dist_s[k] + dist_k[t];
    cout << "Shortest distance from " << s << " to " << t << " passing through " << k << ": " << total << endl;

    vector<int> path;

    for (int v = k; v != -1; v = parent_s[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    vector<int> path2;
    for (int v = t; v != -1 && v != k; v = parent_k[v]) {
        path2.push_back(v);
    }
    reverse(path2.begin(), path2.end());

    cout << "Path: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size() - 1 || !path2.empty()) cout << " -> ";
    }
    for (int i = 0; i < path2.size(); i++) {
        cout << path2[i];
        if (i < path2.size() - 1) cout << " -> ";
    }
    cout << endl;
}


int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<int,int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int s, t, k;
    cin >> s >> t >> k;

    vector<int> dist_s, parent_s;
    vector<int> dist_k, parent_k;

    Dijkstra(n, adj, s, dist_s, parent_s);
    Dijkstra(n, adj, k, dist_k, parent_k);

    printPath(s, t, k, dist_s, parent_s, dist_k, parent_k);

    return 0;
}