#include<iostream>
using namespace std;
// Fibonacci series: 0,1,1,2,3,5,8,13,21,34
int Fibonacci(int n){
    if(n==0 || n==1) return n;
    int ans=Fibonacci(n-1)+Fibonacci(n-2);
    return ans;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int result=Fibonacci(n);
    cout<<result<<" ";


    return 0;
}