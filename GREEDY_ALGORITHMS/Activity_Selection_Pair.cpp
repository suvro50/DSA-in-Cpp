#include<iostream>
#include<vector>
#include <algorithm> // Required for sort
using namespace std;

int cmp(pair<int,int>& p1, pair<int,int>& p2){

    return p1.second < p2.second;
}
void maximum_possible_meeting(vector< pair<int,int> >& v){

    if(v.size()==0){
        cout << "Total meeting: 0" << endl;
        return ;
    }
    sort(v.begin(),v.end(),cmp);
    int count=1;
    int last_end_time=v[0].second;

    cout << "Selected Meeting: {" << v[0].first << ", " << v[0].second << "}" << endl;

    for(int i=1; i<v.size(); i++){
        
        if(v[i].first >= last_end_time){
            count++;
            last_end_time=v[i].second;
            cout << "Selected Meeting: {" << v[i].first << ", " << v[i].second << "}" << endl;
        }
    }

    cout << "Total meetings possible: " << count << endl;

}

int main(){
    
  vector< pair<int,int> > v = { {1,3}, {4,5}, {4,6}, {4,5}, {4,7}, {7,9} };
   

   maximum_possible_meeting(v);


    return 0;
}