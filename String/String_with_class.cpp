#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    string name;
    int id;
    student(string name,int id){
        this->name=name;
        this->id=id;
    }
    void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Id: "<<id<<endl;
        
    }

};

void change_name(student& s){
    s.name="Adi";
    s.id=200;
    s.print();
}

int main(){
    student s("Suvrojit",374);
    s.print();
    
    change_name(s);
  

    return 0;
}