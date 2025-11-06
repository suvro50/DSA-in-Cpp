#include<iostream>
using namespace std;

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