#include<iostream>
#include<map>
using namespace std;

int main(){

    multimap<string,int> mp;


    //multimap print same name key multipul time, that normal map can't do
    // for printing multimap , we need emplase or insert

    mp.insert({"Tv",100});  // insert need pair
    mp.emplace("Tv",200);
    mp.emplace("Tv",100);
    mp.emplace("Tv",100);

    mp.erase(mp.find("Tv")); // delete first finded Tv
    for(auto p:mp){
        cout<<p.first<<" "<<p.second<<endl;
    }

    mp.erase("Tv");  // earse all Tv named data 
    
    cout<<"\nAfter erase\n";
    for(auto p:mp){
        cout<<p.first<<" "<<p.second<<endl;
    }


    return 0;
}