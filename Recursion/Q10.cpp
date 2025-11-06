#include<iostream>
using namespace std;
int smallest_element(int arr[], int n, int index=0){


    if(index == n-1){
        return arr[index];
    }
    int min=smallest_element(arr,n,index+1);

    if(arr[index]< min){
        return arr[index];
    }else{
        return min;
    }
}


int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

  int ans=smallest_element(arr, n);
  cout << "Smallest element: "<<ans;
    return 0;
}