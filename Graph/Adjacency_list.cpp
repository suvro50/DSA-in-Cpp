#include<iostream>
#include<vector>
using namespace std;

struct edge{
    int start;
    int end;

    edge(int start,int end){
        this->start=start;
        this->end=end;
    }
};

struct edge2{
    int start;
    int end;
    int wt;

    edge2(int start,int end,int wt){
        this->start=start;
        this->end=end;
        this->wt=wt;
    }

};

void unweighted_graph(vector<edge> graph[]){

    graph[0].push_back(edge(0,2));

    graph[1].push_back(edge(1,2));
    graph[1].push_back(edge(1,3));

    graph[2].push_back(edge(2,0));
    graph[2].push_back(edge(2,3));
    graph[2].push_back(edge(2,1));

    graph[3].push_back(edge(3,1));
    graph[3].push_back(edge(3,2));
    
}


void weighted_graph(vector<edge2> graph[]){

    graph[0].push_back(edge2(0,2,2));
    
    graph[1].push_back(edge2(1,2,10));
    graph[1].push_back(edge2(1,3,0));

    graph[2].push_back(edge2(2,0,2));
    graph[2].push_back(edge2(2,3,-1));
    graph[2].push_back(edge2(2,1,10));

    graph[3].push_back(edge2(3,1,0));
    graph[3].push_back(edge2(3,2,-1));
    

}





int main(){
    int v=4;
    vector<edge> graph[v];

    // Unweighted graph
    unweighted_graph(graph);

    cout<<"Neibour of vertex 2 is : ";
    for (int i = 0; i <graph[2].size(); i++) {
    cout << graph[2][i].end << " ";
    }
    cout<<endl;


    // weighted graph
    vector<edge2> graph2[v];
    weighted_graph(graph2);

    cout << "Neighbours of vertex 2 in weighted graph: "<<endl;
    for(int i=0;i<graph2[2].size();i++){
        cout<<"vertex "<<graph2[2][i].end<<" with weight: "<<graph2[2][i].wt<<endl; 
    }
    
   return 0;
}