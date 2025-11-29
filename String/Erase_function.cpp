#include<iostream>
#include<string>
using namespace std;

int main(){
    string str="Hello world";
   

    //str.erase(pos, count);  pos=where to start , count=how many charector delete
    str.erase(1,6);  // From index 0 , delete 5 character
    cout<<str<<endl;

    

    return 0;
}