#include<iostream>
#include<unordered_map>
using namespace std;

//  Hash Table / HashMap / Unordered Map   , All are same

int main(){

    // VVI    T.C= O(1)

    // key + value must declear
    unordered_map<string,int> mp;

    // values can't be sorted and Dublicate in Unordered_map.
    // values, key or any  other element can't sort in any order
    mp.insert({"Tv",50}); 
    mp.emplace("Laptop",200);
    mp.emplace("Fridge",100);
    mp.emplace("Phone",100);

     for(auto p:mp){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl<<mp["Laptop"]<<endl;

    return 0;
}
// Best initializition tecnic

// unordered_map<char,int> mp = {
//     {'I',1},
//     {'V',5},
//     {'X',10},
//     {'L',50},
//     {'C',100},
//     {'D',500},
//     {'M',1000}
// };
