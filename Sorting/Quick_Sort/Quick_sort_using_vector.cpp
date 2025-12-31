#include<iostream>
#include<vector>
using namespace std;


// Assume pivot as a last element in array 
// put pivot in middle , and leser value than pivot put left side , and larger value put right side  

// Now use same quick sort algo , left and right part

int partition(vector<int>& arr,int start ,int end){
    int idx=start-1;  // stay in -1 postion , and it make  positon for left element 
    int pivot=arr[end];

    for(int i=start; i< end ;i++){

        if(arr[i] <= pivot){
            idx++;  // create place for last element 
            swap(arr[i],arr[idx]);
        }
    }
    idx++;
    swap(arr[idx],arr[end]);  // lastly swap pivot with index , mean it put in middle position

    return idx;
}

void Quick_sort(vector<int>& arr,int start,int end){

    if(start < end){
    int pivot=partition(arr,start,end);  // This function find pivot and divide laft and right half

    Quick_sort(arr,start,pivot-1);
    Quick_sort(arr,pivot+1,end);
    }

}
int main(){

    vector<int> arr={4,-5,-6,3,6};
    int n=arr.size();

    Quick_sort(arr,0,n-1);

    for(auto i:arr){
        cout<<i<<" ";
    }



    return 0;
}