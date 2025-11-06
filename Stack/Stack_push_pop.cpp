#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;  //create stack

    s.push(3);
    s.push(4);
    s.push(9);

    s.pop(); // delete element from top
    

    cout<<"Top element: "<<s.top()<<endl;

    cout<<"Stack size: "<<s.size()<<endl;

    if(s.empty()){
        cout<<"!Stack is empty.."<<endl;
    }else{
        cout<<"Stack is not empty..";
    }
   


    return 0;
}