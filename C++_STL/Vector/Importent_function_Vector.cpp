#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v;

    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(7);
    v.push_back(2);

    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

   
    cout<<v[1]<<endl; // pass index and it print value..

    cout<<"Front element: "<<v.front()<<endl;
    cout<<"Back element: "<<v.back()<<endl;

    // erase function need O(n) time 

    v.erase(v.begin());  // erase or remove element form begin
    v.erase(v.end()-1);  // erase or remove element form last ,, must end()-1

    cout<<"After erase element: "<<endl;
     for(int i:v){
        cout<<i<<" ";
    }


    // insert() function , put element any where.. .   First pass ,than value (position ,value)..

    v.insert(v.begin(),70);
    cout<<"\nAfter insert element: "<<endl;
     for(int i:v){
        cout<<i<<" ";
    }
    //v.clear(); // clear all vector , except capacity.


    //Also have this operations
    // emplace_front , emplace_back
    // size , erase, clear, begin, end,rbegin, rend, insert, fornt, back

    return 0;
}