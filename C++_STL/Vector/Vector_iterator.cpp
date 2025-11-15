#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v={2,4,5,2,4};

    //vector<int>:: iterator it;  // using auto don't need to write this 

    for(auto it=v.begin(); it!=v.end(); it++){  // It direct find memory location
        cout<<*it<<" ";
    }
    

    cout<<"\nReverce iterator: \n";
    for(auto it=v.rbegin(); it!=v.rend(); it++){
        cout<<*it<<" ";
    }

    return 0;
}