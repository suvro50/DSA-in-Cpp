#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Meeting{
    string name;
    int start;
    int end;

    void print(){
        cout<<"Metting name: "<<name<<endl;
        cout<<"Start time: "<<start<<endl;
        cout<<"End time: "<<end<<endl;
    }
};

bool cmp(const Meeting& m1, const Meeting& m2){

    if(m1.end==m2.end){
        return m1.start < m2.start; // if end times equal, earlier start comes first
    }

    return m1.end < m2.end; // otherwise, sort by end time
}

void maximum_possible_meeting(vector<Meeting>& v) {

    if (v.empty()) {
        cout << "Total meetings possible: 0"<<endl;
        return;
    }

    sort(v.begin(), v.end(), cmp);


    vector<Meeting> selected;

    selected.push_back(v[0]);  //Add first meeting
    int count = 1;
    int first_end_time = v[0].end;

    for(int i=1;i<v.size();i++){

        if(v[i].start>=first_end_time){
            selected.push_back(v[i]);
            count++;
            first_end_time=v[i].end;
        }
    }

     cout<<"\nTotal meetings possible: " << count << endl;
    for(auto i:selected){
        i.print();
    }

}

int main(){

    int n;
    cout<<"Enter total number of metting: ";
    cin>>n;

    vector<Meeting> vc(n);

     cin.ignore();     // clear after reading n

    for(int i=0;i<n;i++){

        cout<<"Enter details for Metting no "<<i+1<<": "<<endl;

        cout<<"Enter name: ";
        getline(cin, vc[i].name);

        cout<<"Enter start time: ";
        cin>>vc[i].start;
        cout<<"Enter end time: ";
        cin>>vc[i].end;

        cin.ignore();  // <-- clear newline for next loop

    }

    maximum_possible_meeting(vc);



    return 0;
}