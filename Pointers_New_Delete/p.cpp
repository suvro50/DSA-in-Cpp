#include<iostream>
using namespace std;

int main(){
    int a=4;

    int* ptr=&a; // store address of a in pointer

    cout<<ptr<<endl;  // Print address
    cout<<*ptr<<endl;  //print value


    return 0;
}