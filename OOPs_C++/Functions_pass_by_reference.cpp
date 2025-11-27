#include<iostream>
using namespace std;

class person{
    public:
    string name;
    int age;
    double salary;

    person() {}  // default constructor

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

void print(person &p){   // pass by reference
    
    p.name="suvrojit";
    p.age=20;
    p.salary=150000;
}

int main(){
    person p;
    print(p);
    return 0;
}