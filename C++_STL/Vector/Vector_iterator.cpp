//#include<bits/stdc++.h>  All hedar file include
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    vector<int> v={2,4,5,2,4};

    //vector<int>:: iterator it;  // using auto don't need to write this 

    for(auto i=v.begin(); i!=v.end(); i++){  // It direct find memory location
        cout<<*i<<" ";
    }
    

    // cout<<"\nReverce iterator: \n";
    // for(auto i=v.rbegin(); i!=v.rend(); i++){
    //     cout<<*i<<" ";
    // }

    cout<<endl;
    reverse(v.begin(),v.end());

    for(auto i:v){
     cout<<i<<" ";
    }

    return 0;
}