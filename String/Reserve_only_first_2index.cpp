#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){

    string str1="Data Structure ";
    string str2="Algoritham";

    reverse(str1.begin(),str1.begin()+2);

    for(auto i:str1){
        cout<<i;
    }

  return 0;

}