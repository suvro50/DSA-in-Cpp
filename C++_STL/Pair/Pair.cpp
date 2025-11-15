#include<iostream>
using namespace std;

int main(){

    pair<int,int> p={3,4};

    cout<<p.first<<" "<<p.second<<endl;

    pair<int, pair<char,int>> p2={6,{'a',7}}; // pair of pair

    cout<<p2.first<<endl;
    cout<<p2.second.first<<endl;
     cout<<p2.second.second<<endl;



    return 0;
}