#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct edge{
    int start;
    int end;

    edge(int start,int end){
        this->start=start;
        this->end=end;
    }

};



void unweighted(vector<edge> graph[]){
    graph[0].push_back(edge(0,1));
    graph[0].push_back(edge(0,2));

    graph[1].push_back(edge(1,0));
    graph[1].push_back(edge(1,3));

    graph[2].push_back(edge(2,0));
    graph[2].push_back(edge(2,4));

    graph[3].push_back(edge(3,1));
    graph[3].push_back(edge(3,4));
    graph[3].push_back(edge(3,5));

    graph[4].push_back(edge(4,2));
    graph[4].push_back(edge(4,3));
    graph[4].push_back(edge(4,5));

    graph[5].push_back(edge(5,3));
    graph[5].push_back(edge(5,4));
    graph[5].push_back(edge(5,6));

    graph[6].push_back(edge(6,5));
}


void parths_find_using_DFS(vector<edge> graph[], int v,int start,int end){

    stack<int> s;
    vector<bool> visited(v,false);

    s.push(start);
    visited[start]=true;

    vector<int> p;
    while(!s.empty()){
        int curr=s.top();
        s.pop();
        p.push_back(curr);
        if(curr==end){

            for(int val:p){
          cout<<val<<" ";
          }
            continue;
        }

        for(int i=0;i<graph[curr].size();i++){
            int neighbor=graph[curr][i].end;
            if(visited[neighbor]==false){
                visited[neighbor]=true;
                s.push(neighbor);
            }
        }
    }
    
    cout<<endl;

}

int main(){

    //     1 ---- 3
    //   /        | \
    //   0        |  5 -- 6
    //   \        | /
    //    2 ----- 4 

    int v=7;

    vector<edge> graph[v];

    unweighted(graph);

    parths_find_using_DFS(graph,v,0,5);

    return 0;
}