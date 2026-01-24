#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

// Prim's algorithm using adjacency matrix internally
int MST_Prims(int v, vector< vector<int> >& graph){
    // {weight, node} for pair<int,int>

    // greater<pair<int,int>> for ascending sort , priority_queue by default max heap
    
    // Priority queue: {weight, {parent, current}}
    priority_queue< pair<int,pair<int,int> > , vector< pair< int,pair<int,int> > > ,greater< pair<int,pair<int,int> > >  > pq;

   pq.push({0, {-1, 0}});  // {weight, {parent, current node}}

    vector<bool> visited(v, false);

     int mstcost=0;

    while(!pq.empty()){
       auto top=pq.top();
       pq.pop();

       int weight = top.first;   // weight
       int parent = top.second.first;  // parent
       int curr = top.second.second; // current node

        if (visited[curr]){
            continue;
        }
        visited[curr] = true;
        mstcost += weight;

        if (parent != -1) {
            cout << parent << " - " << curr << "  weight: " << weight << "\n";
        }

     // Push adjacent nodes into the priority queue
        for (int i = 0; i < v; i++) {
            if (graph[curr][i] != 0 && !visited[i]) {
                pq.push({graph[curr][i], {curr, i}});
            }
        }
    }

    return mstcost;
   
}
int main(){
     int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter edges (start_vertex, end_vertex, weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // because undirected graph
    }

    int cost = MST_Prims(V, graph);
    cout << "Total MST cost = " << cost << endl;
    return 0;
}

// input: 
// 4 4
// 0 1 2
// 0 3 6
// 1 2 3
// 1 3 8