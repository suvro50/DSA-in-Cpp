#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;


int MST_Prims(int v, vector< vector<int> >& graph){
    // {weight, node} for pair<int,int>

    // greater<pair<int,int>> for ascending sort , priority_queue by default max heap
    
    // Priority queue: {weight, {u, v}}
    priority_queue< pair<int,pair<int,int> > , vector< pair< int,pair<int,int> > > ,greater< pair<int,pair<int,int> > >  > pq;

    pq.push({0, { -1, 0 }}); // {weight, {parent, current node}}

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
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            cin >> graph[i][j];
       }
    }

    int cost = MST_Prims(V, graph);
    cout << "Total MST cost = " << cost << endl;

    return 0;
}