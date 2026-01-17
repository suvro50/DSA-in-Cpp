#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

  // Minimum Spanning Tree (MST) is a greedy algorithms.
  //If a graph has no weights, an MST is not possible.

  // A tree which we have, n nodes and n-1 edges & all nodes are rechable from each other , that is spanning tree
  // Any tree with the least sum is a MST , sum= weight sum , so minimum number of sum is MST , A graph should have multiple MST 

void makeset(vector<int>& parent, vector<int>& rank ,int n){

    for(int i=0;i<n;i++){
        parent[i]=i;  // own parent own 
        rank[i]=0;  // first ranks 0 , all sets
    }
}

int findparent(vector<int>& parent, int node){  // find parent

    if(parent[node] != node){  // means own parent own  ,, when it reached to top than it stop
        parent[node]=findparent(parent , parent[node]);
    }

    return parent[node];
     
}

void union_set(vector<int>& parent ,vector<int>& rank, int x , int y){

    // find x & y parent indivisually
    x=findparent(parent,x);

    y=findparent(parent,y);

     if(x == y) return;   // already same set

    if(rank[x] > rank[y]){
        parent[y]=x;
    }else if (rank[y] > rank[x]){
        parent[x]=y;
    }else{
        // Make parent anyone
        parent[x]=y;  
        rank[y]++;
    }
}

bool cmp(vector<int>& a, vector<int>& b){
    return a[2] < b[2];
}
// --------------------- Kruskal MST ---------------------
int kruskalMST(vector< vector<int> >& edges, int n ){

    sort(edges.begin(),edges.end(),cmp);

    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent,rank,n);
    int minweight=0;

    for(int i=0;i<edges.size();i++){
        int a=findparent(parent,edges[i][0]);
        int b=findparent(parent,edges[i][1]);
        int wt =edges[i][2];

        if(a != b){
            minweight +=wt;
            union_set(parent,rank,a,b);
        }

    }

    return minweight;


}
int main() {
    int n, m;  // n = nodes, m = edges

    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges;
    cout << "Enter each edge as: start_node end_node weight" << endl;

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});  // add edge to vector
    }

    int result = kruskalMST(edges, n);

    cout << "Minimum Spanning Tree weight: " << result << endl;

    return 0;
}