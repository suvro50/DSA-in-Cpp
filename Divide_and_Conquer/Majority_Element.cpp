#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v={3,2,3};

    int n=v.size();

    int mej=n/2;

    for(int i:v){
        int count=0;

        for(int j:v){
            if(i==j){
                count++;
            }
        }
        if(count > mej){
            cout<<i;
            break;
        }
    }

    return 0;
}