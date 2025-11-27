#include<iostream>
using namespace std;

// Two pointer always work with sorted array 

pair<int,int> Two_sum(int arr[],int n, int target){
    
    int left=0;
    int right=n-1;
    
    while(left<right){
        int sum=arr[left]+arr[right];

        if(sum==target){
            return {left,right};
        }

        if(sum<target){
            left++;
        }else{
            right--;
        }
    }
    return {-1,-1};
}

int main(){

    int arr[]={1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target=15;

    pair<int,int> result=Two_sum(arr,n,target);

    cout<<result.first<<" "<<result.second<<endl;

    return 0;
}