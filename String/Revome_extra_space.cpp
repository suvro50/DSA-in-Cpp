#include<iostream>
#include<string>
using namespace std;

int main(){

    string str1="Hello wor ld";
    string result;

  
   for(int i=0;i<str1.length();i++){

    if(str1[i]!=' ') result+=str1[i];

   }
   
   cout<<result<<endl;

    return 0;
}