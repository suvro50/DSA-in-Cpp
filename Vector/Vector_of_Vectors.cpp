#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<vector<int>> v;

    v.push_back({1,2});
    v.push_back({3,2});
    v.push_back({5});

    v.push_back({4,5,6,7});

  for (const auto row : v) {
        for (int x : row)
            cout << x << " ";
        cout << endl;

    }


//    for(int i=0; i<v.size(); i++){

//     for(auto it=v[i].begin(); it!=v[i].end(); it++){
//         cout<<*it<<" ";
//     }
//     cout<<endl;
//    }

    return 0;
}
