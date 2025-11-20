#include<iostream>
#include<string>
using namespace std;

int main(){
    string str="Hello";

    //str.insert(1, " oky "); // insert postion , with value
   // str.append(" suvor");

    // replace(index, how many charector want replace,   string);

    str.replace(1,4," hi ");
    cout<<str<<endl;


    return 0;
}