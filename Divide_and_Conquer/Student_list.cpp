#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class student{

    public:

    string name;
    int id;
    double cgpa;
    student(string name, int id, double cgpa){
        this->name=name;
        this->id=id;
        this->cgpa=cgpa;
    }

    void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Id: "<<id<<endl;
        cout<<"Cgpa: "<<cgpa<<endl;

        cout<<endl;

    }

};

bool sortcgpa(student& a, student& b){

   return a.cgpa > b.cgpa; 

}

int main(){

    vector<student> vc;

    vc.emplace_back("suvrojit",374,3.50);
    vc.emplace_back("Adi",290,3.20);
    vc.emplace_back("Dip",174,3.70);


    sort(vc.begin(), vc.end(),sortcgpa);

    for(auto i:vc){
        i.print();
    }

    return 0;
}