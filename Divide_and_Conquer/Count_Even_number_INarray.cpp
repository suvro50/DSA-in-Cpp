#include<iostream>
using namespace std;

int count_even(int arr[],int start,int end){

    

    if(start==end){   // Base case only one element

       if(arr[start]%2==0){
         return 1;
       }else return 0;

    }
   
        int mid=start+ (end-start)/2;

        int left=count_even(arr,start,mid);
        int right=count_even(arr,mid+1,end);

        int ans=left+right;
       
    return ans;

}

int main(){

    int arr[]={5,2,6,8,10,12,14,15,13};

    int n= sizeof(arr) / sizeof(arr[0]);

    int ans=count_even(arr,0,n-1);
    cout<<ans;

    return 0;
}