#include<bits/stdc++.h>
using namespace std;

pair<int,int> largestPair(const vector<int>& vc,int start, int end){
    
    int n=vc.size();
    if (n < 2) return {0, 0};

  // Only 1 element avalable
    if(start==end){ 
        return { vc[start], INT_MIN};
    }

    // Only 2 element avalable

    if(start==end-1){  

        if(vc[start] > vc[end] ){

        return { vc[start], vc[end] };

        }else {
            return  { vc[end], vc[start] };
        }

    }


    int mid=start+ (end-start)/2;

    pair<int,int> leftpair=largestPair(vc,start,mid);
    pair<int,int> rightpair=largestPair(vc,mid+1,end);

    pair<int,int> crosspair={ leftpair.first,rightpair.first };

    
    
    int leftsum= leftpair.first+leftpair.second;
    int rightsum= rightpair.first+rightpair.second;

    int crosssum= crosspair.first+crosspair.second;


    if(leftsum>=rightsum && leftsum>=crosssum){
     return leftpair;

    }else if(rightsum>=leftsum && rightsum>=crosssum){
        return rightpair;
    }else {
        if(crosspair.first < crosspair.second){
            swap(crosspair.first,crosspair.second);
        }
         return crosspair;
    }


}

int main(){

    vector<int> vc={100, -1, -99, -98};

    int size=vc.size();

     pair<int,int> ans = largestPair(vc, 0, size-1);

    cout << "Largest pair: (" << ans.first << ", " << ans.second << ")\n";




    return 0;
}