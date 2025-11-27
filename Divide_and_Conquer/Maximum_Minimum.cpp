#include<iostream>
using namespace std;

struct mypair{

    int mymax;
    int mymin;

};


mypair findMax(int arr[], int start, int end){

    mypair p;
    if (start==end){
        p.mymax=arr[start];
        p.mymin=arr[start];

    }else if (start==end-1){

        if(arr[start]>arr[end]){

            p.mymax=arr[start];
            p.mymin=arr[end];
        }else{
            p.mymax=arr[end];
            p.mymin=arr[start];
        }
    }else{
        int mid=start+(end-start)/2;

        mypair l=findMax(arr,start,mid); //T(n/2)

        mypair r=findMax(arr,mid+1,end); //T(n/2)

        p.mymax= max(l.mymax , r.mymax);
        p.mymin= min(l.mymin , r.mymin);


    }
    return p;
}

int main(){

    int arr[]={11,2,-1,21,3,20,-20,-42};

    int n= sizeof(arr) / sizeof(arr[0]);

    mypair ans=findMax(arr,0,n-1);

    cout<<"Max : "<<ans.mymax<<endl;
    cout<<"Min : "<<ans.mymin<<endl;




    return 0;
}