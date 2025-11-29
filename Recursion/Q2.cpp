#include<iostream>
using namespace std;

// Calculate the sum from 1 to n
int Calculate_sum(int n){
    if(n==0) return 0;

    int ans= n + Calculate_sum(n-1);
    return ans;
    
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<Calculate_sum(n);
    
    return 0;
}