#include<iostream>
#include<string>
using namespace std;

int main(){
    // string str;

    // cout<<"Enter string: ";
    // getline(cin,str);

    // cout<<str;

    // Combine 2 string.

    string str1="Hello ";
    string str2="Bello ";

    string str3=str1+str2;
    cout<<str3<<endl;

     // for(auto i: str3) cout<<i; 

    // string length..
    cout<<"\nstring length: "<<str3.length()<<endl;

    // Check 2 string value equal or not 

    cout<<(str1==str2)<<endl;


    // Check which one is grater

    cout<<(str1>str2)<<endl;


    return 0;
}