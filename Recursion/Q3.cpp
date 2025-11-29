#include<iostream>
using namespace std;

// Calculate the factorial of n
int Factorial(int n){
    if(n==0 || n==1) return 1;

   int ans= n * Factorial(n-1);
   return ans;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int ans=Factorial(n);
    cout<<ans;
    return 0;
}