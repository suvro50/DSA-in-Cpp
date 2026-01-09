#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

  // Minimum Spanning Tree (MST) is a greedy algorithms.

  // A tree which we have, n nodes and n-1 edges & all nodes are rechable from each other
  // Any tree with the least sum is a MST , sum= weight sum , so minimum number of sum is MST , A graph should have multiple MST 

void makeset(vector<int>& parent, vector<int>& rank ,int n){

    for(int i=0;i<n;i++){
        parent[i]=i;  // own parent own 
        rank[i]=0;  // first ranks 0 , all sets
    }
}

int findparent(vector<int>& parent, int node){  // find parent

    if(parent[node] == node){  // means own parent own  ,, when it reached to top than it stop
        return node;
    }

    return parent[node]=findparent(parent , parent[node]);
     
}

void union_set(vector<int>& parent ,vector<int>& rank, int u , int v){

    // find u & v parent indivisually
    u=findparent(parent,u);

    v=findparent(parent,v);

     if(u == v) return;   // already same set

    if(rank[v] > rank[u]){
        parent[u]=v;
    }else if (rank[u] > rank[v]){
        parent[v]=u;
    }else{
        parent[v]=u;
       rank[u]++;
    }
}
// --------------------- Kruskal MST ---------------------
int kruskalMST(vector< vector<int> >& edges, int n ){

    // do from here

}
int main(){




    return 0;
}