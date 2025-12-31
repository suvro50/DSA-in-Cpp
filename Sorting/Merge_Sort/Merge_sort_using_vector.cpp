#include<iostream>
#include<vector>
using namespace std;



// Merge sort is a : Deivde and conquere algorithm

// Best Case: O(n log n)

// Average Case: O(n log n)

// Worst Case: O(n log n)

// Space Complexity: O(n)

void merge_Two_part(vector<int> &arr,int start,int mid,int end){

    vector<int> temp;

    int i=start; // i run till mid from start 
    int j=mid+1; // j run till end form mid+1

    while(i<=mid && j<=end){
        
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){  // if element of i not finish
        temp.push_back(arr[i]);
        i++;
    }

     while(j<=end){  // if element of j not finish
        temp.push_back(arr[j]);
        j++;
    }

    //store temp in real array
    for(int i=0;i<temp.size();i++){
        arr[i+start]=temp[i];
    }

   // temp is temporary storage for merging.

  // arr[i + start] = temp[i] ensures that the sorted subarray goes back into its original position in the main array.

}


// This function sort the array
void mergeSort(vector<int> &arr,int start,int end){
    if(start<end){

        int mid=start+(end-start)/2;

        mergeSort(arr,start,mid);  //left side
        mergeSort(arr,mid+1,end);  //right side

        merge_Two_part(arr,start,mid,end);

    }

}


int main(){

    vector<int> arr={4,6,7,8,-2,1};

    mergeSort(arr,0,arr.size()-1);

    for(int val:arr){
        cout<<val<<" ";
    }
    cout<<endl;


    return 0;
}