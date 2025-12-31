#include <bits/stdc++.h>
using namespace std;

int crossSubArray(int arr[],int l,int mid,int r){
    
    int leftSum = INT_MIN;
    int sum=0;
    for(int i=mid;i>=l;i--){   // Must need to touch mid , For Continuous Subarray Sum
        
        sum+=arr[i];

        if(sum > leftSum){
            leftSum=sum;
        }
    }

    int rightSum=INT_MIN;
    sum=0;

    for(int i=mid+1;i<=r;i++){

        sum+=arr[i];
        if(sum > rightSum){

        rightSum=sum;
        }
    }
    
    return leftSum+rightSum;
}


int maxSubArray(int arr[],int l,int r){
    if(l==r)
    {
        return arr[l];
    }

    int mid = l+(r-l)/2;
    
    int left = maxSubArray(arr,l,mid);
    int right=maxSubArray(arr,mid+1,r);
    int cross=crossSubArray(arr,l,mid,r);

    return max( {left, right, cross} );
}



int main(){
    int arr[]={-3,1,3,4,5,2};

    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<maxSubArray(arr,0,n-1);
}