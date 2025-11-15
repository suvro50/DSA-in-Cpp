#include<iostream>
#include<vector>
using namespace std;

int main(){
    //The number of rows is locked at 5
    vector<int> v[5];  // here row number be same , eash number of row have 1 vector

    v[0].push_back(1);
    v[0].push_back(3);
    v[0].push_back(30);
    v[0].push_back(40);
    v[0].push_back(32);
    v[0].push_back(87);

    v[1].push_back(2);

    v[3].push_back(2);
    v[3].push_back(4);



    for (const auto &row : v) {      // row is each vector<int>
    for (int x : row){              // x is each element
        cout << x << " ";
    }
    cout << endl;
}
//    for(int i=0;i<5;i++){
//     for(int j=0;j<v[i].size();j++){
//         cout<<v[i][j]<<" ";
//     }
//     cout<<endl;
//    }

    return 0;
}