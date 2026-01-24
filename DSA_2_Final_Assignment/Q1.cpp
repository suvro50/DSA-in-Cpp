#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void makeset(vector<int>& parent, vector<int>& rank, int n) {
    for (int i = 0; i <= n; i++) { 
        parent[i] = i;
        rank[i] = 0;
    }
}

int findparent(vector<int>& parent, int node) {
    if (parent[node] != node) {
        parent[node] = findparent(parent, parent[node]);
    }
    return parent[node];
}

void union_set(vector<int>& parent, vector<int>& rank, int x, int y) {
    x = findparent(parent, x);
    y = findparent(parent, y);

    if (x == y) return;

    if (rank[x] > rank[y]) {
        parent[y] = x;
    } else if (rank[y] > rank[x]) {
        parent[x] = y;
    } else {
        parent[x] = y;
        rank[y]++;
    }
}


bool cmp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

bool outputCmp(vector<int>& a, vector<int>& b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] < b[1];
}


int kruskalMST(vector<vector<int>>& edges, vector<vector<int>>& mst_edges, int n, int skipID) {
    
    vector<int> parent(n + 1);
    vector<int> rank(n + 1);
    makeset(parent, rank, n);
    
    int minweight = 0;
    int count = 0;
    mst_edges.clear();

    for (int i = 0; i < edges.size(); i++) {
        
        if (edges[i][3] == skipID) continue;

        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        int a = findparent(parent, u);
        int b = findparent(parent, v);

        if (a != b) {
            minweight += wt;
            union_set(parent, rank, a, b);
            mst_edges.push_back(edges[i]);
            count++;
        }
    }

    if (count != n - 1) return 100000000;

    return minweight;
}

// Print Function 
void printSolution(int weight, vector<vector<int>>& edges) {
    cout << "Second Best MST Weight: " << weight << endl;
    cout << "Edges in Second Best MST:" << endl;

   
    for (int i = 0; i < edges.size(); i++) {
        if (edges[i][0] > edges[i][1]) {
            swap(edges[i][0], edges[i][1]);
        }
    }

    sort(edges.begin(), edges.end(), outputCmp);

    for (int i = 0; i < edges.size(); i++) {
        cout << edges[i][0] << " - " << edges[i][1] 
             << " (" << edges[i][2] << ")" << endl;
    }
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        edges.push_back({u, v, wt, i}); 
    }

    sort(edges.begin(), edges.end(), cmp);

    vector<vector<int>> first_mst;
    
    
    kruskalMST(edges, first_mst, n, -1);

    int second_best_weight = 100000000;
    vector<vector<int>> second_best_edges;

    for (int i = 0; i < first_mst.size(); i++) {
        vector<vector<int>> temp_edges;
        int skip_edge_id = first_mst[i][3];

        int current_weight = kruskalMST(edges, temp_edges, n, skip_edge_id);

        if (current_weight <= second_best_weight) {
            second_best_weight = current_weight;
            second_best_edges = temp_edges;
        }
    }

    printSolution(second_best_weight, second_best_edges);

    return 0;
}