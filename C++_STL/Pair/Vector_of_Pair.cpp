#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<pair<int,int>> v={{1,2}, {3,4}, {5,6}, {7,8}};

    for(auto i:v){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl<<"After push back: "<<endl; 
    v.push_back({11,12}); // need predefind pair..

    v.emplace_back(14,15); // it make pair automaticly..  // it is faster

    for(auto i:v){
        cout<<i.first<<" "<<i.second<<endl;
    }


    return 0;
}