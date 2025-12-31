#include<bits/stdc++.h>
using namespace std;

int main(){
    //it take O(n);

    int arr[]={-3,1,3,4,5,2};
    
    int n=sizeof(arr) / sizeof(arr[0]);
    
    int maximum=INT_MIN;
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum > maximum){
            maximum=sum;
        }
        if(sum < 0){  // if sum is less then 0 , than make it again =0
            sum =0;
        }
    }
    cout<<"Maximum subarray is: "<<maximum;

    

    
    return 0;
}