#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 /* MakeSet: initialize parent and rank */
void makeset(vector<int>& parent, vector<int>& rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;   // each node is its own parent
        rank[i] = 0;     // initial rank is 0
    }
}

int findparent(vector<int>& parent, int node){  // find parent

    if(parent[node] == node){  // means own parent own  ,, when it reached to its own parent , than return
        return node;
    }

    return parent[node]=findparent(parent , parent[node]);   // path compression
     
}

void union_set(vector<int>& parent ,vector<int>& rank, int x , int y){

    // find u & v parent indivisually
    x=findparent(parent,x);

    y=findparent(parent,y);

     if(x == y) return;   // already same set

    if(rank[x] > rank[y]){
        parent[y]=x;
    }else if (rank[y] > rank[x]){
        parent[x]=y;
    }else{
        parent[x]=y;
        rank[y]++;
    }
}

int main(){

    int n=6;  // number of elements 0 to 6

    vector<int> parent(n);
    vector<int> rank(n);

    makeset(parent,rank,n);

     // sample unions

     union_set(parent,rank,0,1);
     union_set(parent,rank,1,2);
     union_set(parent,rank,3,4);
     union_set(parent,rank,2,4);

      // find representative of each element
      for(int i=0;i<n;i++){
        cout<<"Parent of "<<i<<" is "<<findparent(parent,i)<<endl;
      }



    return 0;
}