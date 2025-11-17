#include<iostream>
#include<map>
using namespace std;

int main(){
     // VVI    T.C= O(log(n))

   // map ( key, value)  , map input sintax
   // Exp: m[key]=value

   // same key name value can't print 2 time

    map<string,int> mp;  // empty map

    mp["Laptop"]=100;
    mp["Desktop"]=200;
    mp["Tv"]=150;
    mp["Headphone"]=250;
    mp["Watch"]=120;
    
    // Map automaticly sort the key in ascending order..

    for(auto p:mp) {
        cout<<p.first<<" "<<p.second<<endl;
    }


    cout<<endl<<"After insert: "<<endl;

    mp.insert({"Apple",400});
    mp.emplace("Car",1000);

    
    for(auto p:mp) {
        cout<<p.first<<" "<<p.second<<endl;
    }


    // // mp.count("Laptop")=1 , it count the number of occarence..
    // //mp["Laptop"]=100 ,it print Laptop value

    // cout<<"Count: "<<mp.count("Laptop")<<endl;
    // cout<<"Laptop value: "<<mp["Laptop"]<<endl;

    // mp.erase("Tv"); // it erase the value
    // cout<<"After erase: "<<endl;
    // for(auto p:mp) {
    //     cout<<p.first<<" "<<p.second<<endl;
    // }

  return 0;

}