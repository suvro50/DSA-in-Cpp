#include<iostream>
#include<string>
using namespace std;

int main(){

    string str1;
    cout<<"Enter a stirng: ";
    getline(cin,str1);  // must given for taking string input

  
    for(auto &c:str1){
        c=tolower(c);
    }
    cout<<str1<<endl;

    for(auto &c:str1){
        c=toupper(c);
    }
    cout<<str1<<endl;

    return 0;
}