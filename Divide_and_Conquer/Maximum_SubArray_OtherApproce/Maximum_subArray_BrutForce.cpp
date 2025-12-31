#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={-3,1,3,4,5,2};
    
    int n=sizeof(arr) / sizeof(arr[0]);
    
    int maximum=arr[0];

    for(int i=0;i<n;i++){

        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];

            maximum=max(sum,maximum);  // Compare between INT_MIN and sum , which one is maximum , and of course sum must be max
        }
    }
    cout<<"Maximum subarray is: "<<maximum;

    // But it take O(n^2);

    
    return 0;
}