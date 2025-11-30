#include<iostream>
#include<algorithm>
using namespace std;
// Two pointer-> 2 people work same time , 1st one from left , 2nd one from right
// It divide the work in half time 

// Two pointer always work with sorted array 
// If data not sorted , than sort it first , before applying -> Two pointer

// Two pointer mostly use in : Array , linkedlist , string

// Where is use most : Merge , removve_dublicate , rearange data , or detect cycle in linkedlist
// Also uses: if anser want 2,3,4 or pair , triplets

// If given do not use extra space , than use 2 pointer

// If i sort any array , than it index number also changed-> when need element not want index , than we sort array

pair<int,int> Two_sum(int arr[],int n, int target){
    
    int left=0;
    int right=n-1;
    
    while(left<right){
        int sum=arr[left]+arr[right];

        if(sum==target){
            return {left,right};
        }

        if(sum > target){
            right--;
        }else{
            left++;
        }
    }
    return {-1,-1};
}

int main(){

    int arr[]={1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // sort(arr,arr+n);  // ascending order sort
     //reverse(arr,arr+n); // reverse it , if we want in decending order 
     int target=7;

    pair<int,int> result=Two_sum(arr,n,target);

    cout<<result.first<<" "<<result.second<<endl;
    
    return 0;
}