#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int>& a, pair<int,int>& b){
    return a.second < b.second;
}
void meeting_must_calcle(vector< pair<int,int> >& v){

    if(v.size()==0){
        cout << "Total cancel meeting: 0" << endl;
        return ;
    }
    sort(v.begin(), v.end() , cmp);

    int count=1;
    int last_end_time=v[0].second;

    for(int i=1;i<v.size();i++){

        if(v[i].first >= last_end_time){
            count++;
            last_end_time=v[i].second;
        }
    }

    cout<<"Total cancle meeting: "<<v.size()-count;

}

int main(){

    vector< pair<int,int> > v= { {1,3}, {4,5}, {4,6}, {4,5}, {4,7}, {7,9} };

    meeting_must_calcle(v);

    return 0;
}