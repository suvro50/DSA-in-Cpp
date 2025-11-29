#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){

    string str1="Data Structure ";
    string str2="Algoritham";

    cout<<"Str1 length: "<<str1.length()<<endl;
    char c=str1.at(2); // print index value
    
    cout<<c<<endl;
    cout<<str1[2]<<endl; // another way 

    string course_name=str1+"and "+str2+" 2";
    cout<<course_name<<endl;

    reverse(str1.begin(),str1.end());  // reverse is a void function

    cout<<str1;

  return 0;

}