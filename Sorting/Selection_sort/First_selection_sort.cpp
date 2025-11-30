#include<iostream>
using namespace std;
void swapd(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min =j;
            }
        }
        swapd(arr[min],arr[i]);
    }
    cout<<"After sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n=10;
    int arr[n]={4,4,5,3,2,56,32,7,43,76};
    
    selection_sort(arr,n);

    return 0;
}