#include<iostream>
#include<string>
using namespace std;

int main(){
    string str="Hello world";
    string st="wor";

    //str.insert(1, " oky "); // insert postion , with value
   // str.append(" suvor");

    // replace(index, how many charector want replace,   string);

    // str.replace(1,2," hi ");  // Replace substring
    // cout<<str<<endl;

    int  position =str.find(st); // gives us starting index for the word
    cout<<position<<endl;

    string substring=str.substr(1,5);   // return ( string ) from index 1 to 5
    cout<<substring<<endl;


    return 0;
}