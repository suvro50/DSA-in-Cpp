#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include<algorithm>
using namespace std;
 // priority_queue<int> pq; //max_heap  // by default compiler actually sees : priority_queue<int, vector<int>, less<int>> pq;
// priority_queue<int,vector<int>,greater<int> > pq; //min_heap




void Dijkstra(int V, vector<vector<pair<int,int>>>& adj, int source) {
     // min-heap: {distance, node}
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    vector<int> dist(V, INT_MAX);  // current shortest distence = infinite , for all nodes
    vector<int> parent(V, -1);      // to store path
    dist[source] = 0;

    // Select the node , which is not explore yet and it's dist value: 0
    pq.emplace(0, source);  // push : { distance,node }

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int currDist = top.first; // distance
        int u = top.second;  // node 

        if (currDist > dist[u]) continue; // already found shorter path

        // explore neighbors or Edge Relaxcation
        for (auto edge : adj[u]) {
            int v = edge.first;  // end node 
            int weight = edge.second; // weight

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v]=u;
                pq.emplace(dist[v], v);   // first push distance than node
            }
        }
    }


    cout << "\nShortest paths:\n";
   for (int i = 0; i < V; i++) {

    if (dist[i] == INT_MAX) continue;

    vector<int> p;
    for (int k = i; k != -1; k = parent[k] ) p.push_back(k);
    reverse(p.begin(), p.end());

   for(int j=0;j<p.size();j++){
    cout<<p[j];
    if(j+1 < p.size()) cout<<"->";

   }
    //print cost
    cout << " cost-(" << dist[i] << ")"<<endl;
  }

}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V); // adjacency list

    cout << "Enter edges (start_vertex, end_vertex, weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);


        adj[v].emplace_back(u, w);          // remove this line if graph is directed
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
// 0->1 cost-(4)
// 0->2 cost -(2)
// 0->2->4->3 cost(9)
// 0->2->4 cost(5)
// 0->2->4->3->5 cost(20)