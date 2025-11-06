#include<iostream>
using namespace std;



// array must me sorted to run Binary_search

int binary_search(int arr[],int n,int key){

    int start=0;
    int end=n-1;
    
    while(start<=end){
        int mid =start+(end-start)/2;

        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            start=mid+1;
        }else {
            end=mid-1;
        }
    }
    return -1;
}

int main(){
    
    int arr[6]={-3,2,4,6,7,8};

    int ans=binary_search(arr,6,4);

    if(ans==-1){
        cout<<"Element not exist..";
    }else{
     cout<<"Index of 4 is:"<<ans;
    }

    return 0;
}