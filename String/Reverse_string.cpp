#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
     string str="Hello";

    //  int start=0, end=str.length()-1;

    //  while(start<end){
    //     swap(str[start],str[end]);
    //     start++;
    //     end--;
    //  }
     cout<<str<<endl;

     reverse(str.begin(),str.end());  // #include <algorithm>   , must for reverse
     cout<<str;


    return 0;
}