#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    // VVI    T.C= O(1)

    unordered_map<string,int> mp;

    // values can't be sorted and Dublicate in Unordered_map.
    // values, key -any  other thing can't sort in any order
    mp.insert({"Tv",50}); 
    mp.emplace("Laptop",200);
    mp.emplace("Fridge",100);
    mp.emplace("Phone",100);

     for(auto p:mp){
        cout<<p.first<<" "<<p.second<<endl;
    }




    return 0;
}