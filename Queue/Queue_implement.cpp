#include<iostream>
#include<queue>
using namespace std;

int main(){

    //FIFO(First in First Out),  Data Structure

    queue<int> q;

    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    
    

    cout<<q.front()<<" ";
    cout<<q.back()<<endl;

    cout<<"Size of Queue: "<<q.size()<<endl;



    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is't empty"<<endl;
    }

    return 0;
}