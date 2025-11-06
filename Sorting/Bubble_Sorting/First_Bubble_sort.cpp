#include<iostream>
using namespace std;

void swapd(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void Bubble_sort(int arr[],int n){

    for(int i=0;i<n-1;i++){
        int swp=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]) {
                swapd(arr[j],arr[j+1]);
                swp=true;
            }
        }
        if(!swp) break;
    }

     cout<<"After sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

int main(){
   int n=10;
    int arr[n]={4,4,5,3,2,56,32,7,43,76};
    Bubble_sort(arr,n);
   
   return 0;
}