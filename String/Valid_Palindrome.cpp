#include<iostream>
#include<string>
using namespace std;

int main(){
    string std="0olo0";
    
    // For Alphanumeric : (A–Z, a–z) + Numbers (0–9)
   // isalnew()-> check Alphanumeric or not .

   int start=0, end=std.length()-1;

   while(start<end){

    if( !isalnum(std[start]) ){
        start++;
        continue;
    }
     if( !isalnum(std[end]) ){
        end--;
        continue;
    }

    if(tolower(std[start]) != tolower(std[end])){
        cout<<"Not Palndrome"<<endl;
        return 0;
        
    }

    start++;
    end--;

  }
   cout<<"Palndrome"<<endl;
  
   

    return 0;
}