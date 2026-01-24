#include <bits/stdc++.h>
using namespace std;

int primMST(int V, vector<vector<pair<int,int>>>& adj) {

    // Min-heap: {weight, node}
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    vector<bool> visited(V,false);

    pq.push({0,0}); // {weight, start_node}
    int sum = 0;

    while(!pq.empty()){
        // Extract top
        auto [weight, node] = pq.top(); // structured binding
        pq.pop();

        if(visited[node]) continue;
        visited[node] = true;
        sum += weight;

        for(auto &it: adj[node]){
            int adjnode = it.first;
            int wt = it.second;
            if(!visited[adjnode]){
                pq.push({wt, adjnode}); // {weight, node}
            }
        }
    }
    return sum;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    cout << "Enter edges (start_vertex, end_vertex, weight):\n";
    for(int i = 0; i < E; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    // Build adjacency list
    vector<vector<pair<int,int>>> adj(V);
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }

    int mstCost = primMST(V, adj);
    cout << "Total MST cost: " << mstCost << endl;

    return 0;
}


// input: 
// 4 4
// 0 1 2
// 0 3 6
// 1 2 3
// 1 3 8