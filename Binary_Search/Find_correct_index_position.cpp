#include<iostream>
using namespace std;



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
    return start;
}


int main(){
    int n=6;

    int arr[n]={-3,2,4,6,7,8};

    int key=5;
    int ans=binary_search(arr,n,key);

    if(ans < n && arr[ans] == key){
        cout<<key<< " index= "<<ans<<endl;

    }else{

        for(int i=n; i>ans; i--){
            arr[i]=arr[i-1];
        }
        arr[ans]=key; 
        n++;

        cout<<"After insertion "<<key<<": ";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }

    }


    return 0;
}