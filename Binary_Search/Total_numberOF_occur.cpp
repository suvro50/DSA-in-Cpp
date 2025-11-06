#include<iostream>
using namespace std;

int Binary_search(int arr[],int n,int key,bool found){
    int start=0;
    int end=n-1;
    int result=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key){
            result=mid;
            if(found){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        else if(key<arr[mid]){
            end=mid-1;
        }else{
            start=mid+1;
        }

    }
    return result;
}
int main(){
    int n=6;
    int arr[n]={1,3,3,3,4,4};
    int key=4;

    int left=Binary_search(arr,n,key,true);
    int right=Binary_search(arr,n,key,false);

    if(left==-1){
        cout<<key<<" not found"<<endl;
    }else{
        int ans=(right-left)+1;
        cout<<"Total occurence of "<<key<<" is "<<ans<<endl;
    }

    return 0;
}