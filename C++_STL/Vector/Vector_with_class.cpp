#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class student{

    public:

    string name;
    int id;
    float cgpa;
   student(string name,int id,float cgpa){
    this->name=name;
    this->id=id;
    this->cgpa=cgpa;
   }
   void print(){
    cout<<"Name: "<<name<<endl;
    cout<<"Id "<<id<<endl;
    cout<<"Cgpa: "<<cgpa<<endl;
   }

};



// change id
void change_id(student &s){
    s.id=420;
}


bool sortcgpa(student &s1 ,  student &s2){
    return s1.cgpa>s2.cgpa;
}



void search_by_id(vector<student>& s){
    int id;
    cout<<"Enter searching id: ";
    cin>>id;

    bool found=false;
    for(int i=0;i<s.size();i++){
        cout<<endl;
        if(s[i].id==id){
            found=true;
            cout<<"Here is your student: "<<endl;
            s[i].print();
            break;
        }
    }
    if(!found){
        cout<<"Student not found"<<endl;
    }
}


int main(){

    vector<student> s;
    
    s.emplace_back("Suvro",374,3.50);
    s.emplace_back("Adi",200,2.00);
    s.emplace_back("Dip",200,3.60);

    change_id(s[2]); // change id my passing index

    sort(s.begin(),s.end(),sortcgpa);  // sort by cgpa

    s.erase(s.begin()+1);
    int c=1;
    for(auto i:s){
        cout<<endl;
        cout<<"Student info: "<<c++<<endl;
       i.print();
    }


    search_by_id(s);




    // for(int i=0;i<s.size();i++){
    //  cout<<"Student info: "<<i+1<<endl;
    //    s[i].print();
    // }

    return 0;
}