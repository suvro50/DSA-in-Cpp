#include <iostream>
#include<vector>
using namespace std;

// ✅ Every DP problem supports BOTH Top-Down and Bottom-Up

// ✅ You are free to choose

  // T.C= O(n)
  // S.C= O(n)
   
int fibo(vector<int>& dp , int n){

    // Base case
    if(n==1 || n==0){
        return n;
    }

    // step 2
    if(dp[n] !=-1){
        return dp[n];
    }
    // step 3 
   dp[n]=fibo(dp,n-1)+fibo(dp,n-2);

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    vector<int> dp(n+1,-1);


    for(int i=0;i<n;i++){
        cout<<fibo(dp,i)<<" ";
    }
 
    return 0;
}
