#include<iostream>
#include<vector>
using namespace std;

// Vector Dynamic Allocate Memory , Means run time allocate memory...
int main(){

    vector<int> vc(4,2);

    vector<int> vc;

    cout<<"Size: "<<vc.size()<<endl; // Size of a vector

    cout<<"Size After push_back: "<<vc.size()<<endl; 


    //   cout<<"Capacity: "<<vc.capacity()<<endl; // Vector capacity double when size cross

   vc.pop_back();  // Delete last index value;

      for(int val:vc){  //for each loop 
        cout<<val<<endl;
      } 

    //   cout<<vc.front()<<endl;  //Print first value..

    //   cout<<vc.back()<<endl;  //print last value..

    //   cout<<vc.at(1)<<endl;  //print index 0 value..

    
    return 0;
}