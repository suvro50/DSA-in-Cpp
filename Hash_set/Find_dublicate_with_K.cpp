#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums,int key) {

    unordered_map<int,int> s;

    for(int i=0;i<nums.size();i++){

        if(s.count(nums[i]) && i-s[nums[i]]<=key){
           return true; 
        }
        s[nums[i]]=i;

    }
    return false;

}

int main(){

    vector<int> nums={1,2,3,1,2,3};
    int key=2;

    bool found=containsDuplicate(nums,key);

    if(found){
        cout<<"true";
    }else cout<<"false";




    return 0;
}