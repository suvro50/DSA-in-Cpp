#include <bits/stdc++.h>
using namespace std;

// GFG-style Dijkstra function (unchanged)
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    vector<vector<pair<int,int>>> adj(V);
    for(auto &e : edges){
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // because undirected
    }
    
    priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
    
    vector<int> dist(V,INT_MAX);
    vector<int> parent(V,-1);
    
    dist[src]=0;
    pq.emplace(0,src);
    
    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();
        
        int currdist=top.first; //distance
        int u=top.second; // node
        
        if(currdist > dist[u]) continue;
        
        for(auto e:adj[u]){
            int v=e.first;
            int weight=e.second;
            if(dist[v] > dist[u]+weight){
                dist[v]=dist[u]+weight;
                parent[v]=u;
                pq.emplace(dist[v],v);
            }
        }
    }
    return dist;
}

// Main function
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    cout << "Enter edges (u v w):\n";
    for(int i = 0; i < E; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> dist = dijkstra(V, edges, src);

    cout << "\nShortest distances from vertex " << src << ":\n";
    for(int i = 0; i < V; i++){
        cout << "Vertex " << i << " : " << dist[i] << "\n";
    }

    return 0;
}


//input-2
// 6 8
// 0 1 4
// 0 2 2
// 1 2 5
// 1 4 2
// 1 3 10
// 2 4 3
// 4 3 4
// 3 5 11