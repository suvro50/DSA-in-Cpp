#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key=9;

    unordered_map<int,int> map;  // O(1)

    // first one index , 2nd one value
    map.emplace(0,1);
    map.emplace(1,2);
    map.emplace(2,3);
    map.emplace(3,4);
    map.emplace(4,5);
    map.emplace(5,6);

   



    return 0;
}