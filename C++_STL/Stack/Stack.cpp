#include<iostream>
#include<stack>
using namespace std;

int main(){
    // LIFO -> last in first out
    stack<int> s;

    s.push(5);
    s.push(6);
    s.push(2);
    s.emplace(10);

    cout<<s.top()<<endl;

    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }

    stack<int> s2;

    s2.swap(s);
    cout<<endl<<s.size()<<endl; // size 0
    cout<<s2.size()<<endl; // after swap size=4

    return 0;
}