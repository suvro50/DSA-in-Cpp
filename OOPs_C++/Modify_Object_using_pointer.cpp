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
    void printfun(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Salary: "<<salary<<endl;
    }

    ~person(){   // Destructor , it call autometicly when call class.
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};

void Modify(person* p){
    p->name="Adi";
    p->age=22;
    p->salary=50000;
}

int main(){
    person p("Suvrojit",20,150000);
    //print(p);
    p.printfun();

    cout<<endl<<"After modify: "<<endl;
    Modify(&p);
    return 0;
}