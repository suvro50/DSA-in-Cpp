#include<iostream>
using namespace std;

class person{
    public:
    string name;
    int age;
    double salary;
    person(string name,int age,double salary){
        this->name=name;
        this->age=age;
        this->salary=salary;
    }

    ~person(){   // Destructor , it call autometicly when call class.
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};

int main(){
    person p("Suvrojit",20,150000);
    return 0;
}