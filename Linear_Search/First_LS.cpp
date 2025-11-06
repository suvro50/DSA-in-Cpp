#include<iostream>
using namespace std;

int Linear_search(int arr[],int n,int v){
    for(int i=0;i<n;i++){
        if(arr[i]==v){
            cout<<v<<" Index:"<<i;
            return 1;
        }
    }
    return -1;
}

int main(){
    int n=6;
    int arr[n]={4,6,9,2,5,6};
    int v=5;
    int result=Linear_search(arr,n,v);
    if(result==-1){
        cout<<"Not found";
    }

    return 0;
}
