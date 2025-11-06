#include<iostream>
using namespace std;

int Calculate_sum(int n){
    if(n==0) return 0;

    int ans= n + Calculate_sum(n-1);
   return ans;
    
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int ans=Calculate_sum(n);
    cout<<ans;
    return 0;
}