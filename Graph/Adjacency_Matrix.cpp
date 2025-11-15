#include<iostream>
using namespace std;

 const int v=5;

void unweighted_matrix(int graph[][v]){

    graph[0][1]=graph[1][0]=1;

    graph[0][2]=graph[2][0]=1;

    graph[1][3]=graph[3][1]=1;

    graph[2][4]=graph[4][2]=1;

    graph[3][4]=graph[4][3]=1;

        
}
void print_matrix(int graph[][v]){
    cout << "Adjacency Matrix:\n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    //    1 --- 3
    //   /       \
    //   0        4
    //   \       /
    //    2 -----


    int graph[v][v]={0};   // initialize with 0

    unweighted_matrix(graph);
    print_matrix(graph);

   

    return 0;
}