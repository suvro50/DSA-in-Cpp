#include<iostream>
#include<vector>
using namespace std;


void merge_Two_part(vector<int> &arr,int start,int mid,int end){

    vector<int> temp;

    int i=start;
    int j=mid+1;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

     while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    //store temp in real array
    for(int i=0;i<temp.size();i++){
        arr[i+start]=temp[i];
    }

}


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