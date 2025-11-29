#include<iostream>
using namespace std;

// Find the largest element of given array
int largest_element(int arr[], int n, int index=0){

    if(index == n-1){
        return arr[index];
    }

    int max=largest_element(arr,n,index+1);

    if(arr[index]> max){
        return arr[index];

    }else{
        return max;
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

  int ans=largest_element(arr, n);
  cout << "Largest element: "<<ans;
    return 0;
}