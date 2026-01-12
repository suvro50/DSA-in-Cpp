#include<iostream>
#include<vector>
using namespace std;

// ✅ Every DP problem supports BOTH Top-Down and Bottom-Up

// ✅ You are free to choose

int fibo( int n){
    if(n==0 || n==1) {
        return n;
    }
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){

    int n;
    cout<<"Enter n: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<fibo(i)<<" ";
    }

    return 0;
}