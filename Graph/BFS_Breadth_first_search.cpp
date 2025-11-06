#include<iostream>
#include<vector>
#include<queue>
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
void unweighted_graph(vector<edge> graph[]){

    graph[0].push_back(edge(0,1));
    graph[0].push_back(edge(0,2));

    graph[1].push_back(edge(1,3));
    graph[1].push_back(edge(1,0));

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

void BFS(vector<edge> graph[] , int v, int start){

    queue<int> q;

    vector<bool> visited(v,false);

    q.push(start);
    visited[start]=true;

    while(!q.empty()){
        int curr=q.front();
        q.pop();

        cout<<curr<<" ";

        for(int i=0;i<graph[curr].size();i++){
            int neighbor=graph[curr][i].end;

        if(visited[neighbor]==false){
            visited[neighbor]=true;
            q.push(neighbor);

           }
        }
    }
    cout<<endl;
}

void DFS(vector<edge> graph[], int v, int start){
    stack<int> s;

    vector<bool> visited(v,false);

    s.push(start);
    visited[start]=true;

    while(!s.empty()){
        int curr=s.top();
        s.pop();

        cout<<curr<<" ";

        for(int i=graph[curr].size()-1; i>=0; i--){
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
    unweighted_graph(graph);

    cout<<"Neibours of vertex 5 is: ";
    for(int i=0;i<graph[5].size();i++){
        cout<<graph[5][i].end<<" ";
    }

    cout<<endl;\
    cout<<"BFS traverse: ";
    BFS(graph,v,0);

    cout<<endl;\
    cout<<"DFS traverse: ";
    DFS(graph,v,0);



    return 0;
}
