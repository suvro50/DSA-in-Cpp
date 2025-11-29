#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    char str[n];
    for(int i=0;i<n;i++){
        cin>>str[i];
        str[i]=toupper(str[i]);
    }
   int c1=0,c2=0;

   for(int i=0;i<n;i++){
    if(str[i]=='A'){
        c1++;
    }else if(str[i]=='D'){
        c2++;
    }
   }
   if(c1>c2){
    cout<<"Anton";
   }else if(c1==c2){
    cout<<"Friendship";
   }else{
    cout<<"Danik";
   }
   
   
    return 0;
}