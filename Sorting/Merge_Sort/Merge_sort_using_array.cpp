#include<iostream>
using namespace std;

void merge_twoPart(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2]; // temporary arrays

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge temp arrays back into arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
 

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start+(end-start)/2;

        mergeSort(arr, start, mid);    // go Left side

        mergeSort(arr, mid + 1, end);  // go  Right side

        merge_twoPart(arr, start, mid, end);
    }
}
int main(){
    int n=7;
    int arr[n]={5,7,-1,0,-3,2,3};

    mergeSort(arr,0,n-1);
    
    cout<<"After sorting : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}