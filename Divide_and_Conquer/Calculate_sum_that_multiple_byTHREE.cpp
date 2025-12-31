#include<iostream>
using namespace std;

// calculate the sum of all numbers that are multiple of -> 3

int SUM(int arr[],int start,int end){

    if(start > end){
        return 0;
    }
    
    int sum=0;
    if(start==end){
        if(arr[start]%3==0){

          return arr[start];
        }else return 0;
    }

    
    int mid=start+(end-start)/2;

    int left=SUM(arr,start,mid);
    int right=SUM(arr,mid+1,end);
    return left+right;


}

int main(){

    int arr[]={9, 3, 0, 8, 7, 15, 20};

    int n=sizeof(arr) / sizeof(arr[0]);

    int ans=SUM(arr,0,n-1);

    cout<<ans;
   
    return 0;
}