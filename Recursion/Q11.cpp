#include<iostream>
using namespace std;
void largest_smallest_element(int arr[],int n, int &largest, int &smallest, int index=0){

    if(index == n){
        return;
    }
    
    if(arr[index]>largest){
        largest=arr[index];
    }

    if(arr[index]<smallest){
        smallest=arr[index];
    }

    largest_smallest_element(arr,n,largest,smallest,index+1);

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

    int largest=arr[0];
    int smallest=arr[0];

    largest_smallest_element(arr,n,largest,smallest);
    
    cout << "Largest element: " << largest << endl;
    cout << "Smallest element: " << smallest << endl;

    return 0;
}