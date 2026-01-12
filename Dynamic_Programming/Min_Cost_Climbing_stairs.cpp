#include<iostream>
#include<vector>
using namespace std;

// Tabulation (Bottom-Up) Dynamic Programming method

int minCostClimbingStairs(vector<int>& cost){

    int n=cost.size();
    vector<int> mincost(n+1); 

    mincost[0] = 0;   // cost to start before step 0 is zero
    mincost[1] = 0;   // cost to start before step 1 is zero
 
    for(int i=2;i<=n;i++){

        mincost[i]=min(cost[i-1]+mincost[i-1] , cost[i-2]+mincost[i-2]);
    }

    return mincost[n];
}

int main(){

    int n;
    cout<<"Enter number of Stairs:";
    cin>>n;

    vector<int> cost(n);
    cout<<"Enter per stairs cost: ";
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    
    int ans=minCostClimbingStairs(cost);

    cout<<"Minimum cost: "<<ans<<endl;

    return 0;
}