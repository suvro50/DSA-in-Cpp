#include<iostream>
using namespace std;

// One template declaration applies to ONLY one class or ONE function.

template<typename T> 

class person{
   
 public:
    T details(T a,T b){

     return (a>b)? a : b ;

    }


};

template<typename x,typename y>

class A{    // Multi template class
    public:
    auto print(x a, y b){  // auto key word auto detect return type
        return (a>b)? a : b;
    }
};

int main(){
    person<float> p;   // if you declare a template, you must create objects like person<int>
 
    cout<<p.details(6.4,5.6)<<endl;

    A<float,char> a;
    cout<<a.print(100.2,'z')<<endl;
    return 0;
}