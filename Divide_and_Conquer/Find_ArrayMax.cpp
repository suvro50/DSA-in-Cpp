#include<iostream>
using namespace std;


int findMax(int arr[], int start, int end){
    if (start==end){
        return arr[start];

    }else if (start==end-1){ // when only 2 element avalable

        return (arr[start] > arr[end])? arr[start] : arr[end];

    }else{
        int mid=start+(end-start)/2;

        int left_max=findMax(arr,start,mid); //T(n/2)

        int right_max=findMax(arr,mid+1,end); //T(n/2)

        return (left_max > right_max)? left_max : right_max;

    }
}

int main(){

    int arr[]={11,2,-1,21,3,20,-20};

    int n= sizeof(arr) / sizeof(arr[0]);

    cout<<"Max : "<<findMax(arr,0,n-1);



    return 0;
}