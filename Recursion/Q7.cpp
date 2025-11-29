#include<iostream>
using namespace std;

// Calculate a to the power b
int Power(int a,int b){
  if(b==0){
    return 1;
  }
  
 int result=a*Power(a,b-1);

   return result;
}


int main(){
    int a,b;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter power b: ";
    cin>>b;

    int ans=Power(a,abs(b));  // abs convert all number to positive
    cout<<ans;


    return 0;
}