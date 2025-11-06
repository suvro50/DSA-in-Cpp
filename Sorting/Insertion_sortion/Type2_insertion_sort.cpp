#include<iostream>
using namespace std;
int main(){
     int n=5;
    int arr[n]={5,2,7,4,8};


    for(int i=1;i<n;i++){
      int key=arr[i]; //2,7,4,8
      int j=i-1; //5 to 0

      while(j>=0 && key<arr[j]){  //2<5
        arr[j+1]=arr[j];  //5 shift to position 2 
        j--;
      }

     arr[j+1]=key;   // put key in blank space..
      
  }
    cout<<"After sorting: ";
    for(int val:arr){
        cout<<val<<" ";
    }

    return 0;
}
