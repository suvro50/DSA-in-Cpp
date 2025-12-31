#include<bits/stdc++.h>
using namespace std;

int total_count(int arr[], int start, int end){

   // if(start > end) return 0;

    if(start == end){
        if(arr[start] % 3 == 0 || arr[start] % 7 == 0)
            return 1;
        else
            return 0;
    }

    if(start < end ){
    int mid = (start + end) / 2;
    int left = total_count(arr, start, mid);
    int right = total_count(arr, mid + 1, end);
    return left + right;
    }

    
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = total_count(arr, 0, n - 1);
    cout << ans << endl;

    return 0;
}
