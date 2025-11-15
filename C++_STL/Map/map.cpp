#include<iostream>
#include<map>
using namespace std;

int main(){

   // map ( key, value)  , map input sintax
   // Exp: m[key]=value

    map<string,int> mp;  // empty map

    mp["Laptop:"]=100;
    mp["Desktop:"]=200;
    mp["Tv:"]=150;
    mp["Headphone:"]=250;
    mp["Watch:"]=120;
    
    // it automaticly print key in sorted order..

    for(auto p:mp) {
        cout<<p.first<<" "<<p.second<<endl;
    }

}