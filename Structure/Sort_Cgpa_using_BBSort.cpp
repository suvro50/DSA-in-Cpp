#include<iostream>
using namespace std;

struct student{
    string name;
    double cgpa;
    string DoB;

    student(){}  // Default constructor..

    student(string name,double cgpa,string DoB){
        this->name=name;
        this->cgpa=cgpa;
        this->DoB=DoB;

    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Cgpa: "<<cgpa<<endl;
        cout<<"Date_of_Birth: "<<DoB<<endl;
    }

    int calculate_age(){
        int sum=0;
        int day=stoi(DoB.substr(0,2));
        int month=stoi(DoB.substr(3,2));
        int year=stoi(DoB.substr(6,4));
        return sum=day+month+year;
    }

};
void swapd(student &a,student&b){
    student temp=a;
    a=b;
    b=temp;
}

void Bubble_sort(student s[],int n){
    for(int i=0;i<n;i++){
        bool swp=false;
        for(int j=0;j<n-i-1;j++){

            if(s[j].cgpa<s[j+1].cgpa){

                swapd(s[j],s[j+1]);
                swp=true;
            }
            
            if(s[j].cgpa==s[j+1].cgpa){
                if(s[j].calculate_age()>s[j+1].calculate_age()){
                    swapd(s[j],s[j+1]);
                    swp=true;
                }
            }
        }
        if(!swp){
            break;
        }
    }
}

int main(){ 

    student s[3];

    s[0]=student("Suvrojit",2.10,"10/10/2004");
    s[1]=student("Adi", 3.20,"10/12/2007");
    s[2]=student("Dip",3.01,"10/10/2009");
     

    Bubble_sort(s,3);

    for(int i=0;i<3;i++){
        s[i].display();
        cout<<endl;
    }

    return 0;
}
//wrong in age calculation , correct it Bro..