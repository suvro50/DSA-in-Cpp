#include<iostream>
#include<map>
using namespace std;

int main(){

   // map ( key, value)  , map input sintax
   // Exp: m[key]=value

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

    // find function ..

    if(mp.find("Tv")!=mp.end()){
        cout<<"found"<<endl;
    }else{
        cout<<"Not found"<<endl;
    }

}