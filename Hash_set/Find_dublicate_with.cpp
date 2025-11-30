#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {

    unordered_set<int> s;

    for(int i:nums){
        if(s.count(i)){
           return true; 
        }
        s.insert(i);
    }
    return false;

}

int main(){

    vector<int> nums={1,1,1,3,3,4,3,2,4,2};

    bool found=containsDuplicate(nums);

    if(found){
        cout<<"true";
    }else cout<<"false";




    return 0;
}